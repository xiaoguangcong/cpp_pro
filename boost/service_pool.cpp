// https://zhuanlan.zhihu.com/p/87390640

#include <functional>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

#define BOOST_ASIO_NO_DEPRECATED
#include <boost/thread/thread.hpp>
#include <boost/asio.hpp>

class ThreadPool {
public:
    explicit ThreadPool(std::size_t size) :
        io_context_(size),
        //strand_(io_context_),
        work_guard_(boost::asio::make_work_guard(io_context_))
    {
        // one io_context and multi-thread
        for (std::size_t i = 0; i < size; ++i) {
            // all the threads do is execute the io_context::run()
            group_.create_thread([&](){io_context_.run(); });
        }
    }

    // the destructor joins all threads
    ~ThreadPool() {
        // Once the work object is destroyed, the service will stop.
        work_guard_.reset();
        group_.join_all();
    }

    // Add new work item to the pool
    template<class F>
    void Enqueue(F f) {
        // Submits a completion token or function object for execution.
        boost::asio::post(io_context_, f);
    }

private:
    boost::thread_group group_;
    boost::asio::io_context io_context_;

    // prevent the run() method from return
    typedef boost::asio::io_context::executor_type ExecutorType;
    boost::asio::executor_work_guard<ExecutorType> work_guard_;

    //boost::asio::strand<ExecutorType> strand_;
};

// For output
std::mutex g_io_mutex;

int main(int argc, char* argv[]) {
    int thread_num = std::thread::hardware_concurrency();
    std::cout << "thread num: " << thread_num << std::endl;

    ThreadPool pool(thread_num);
    // Queue a bunch of work items.
    for (int i = 0; i < 4; ++i) {
        pool.Enqueue([i]{
            {
                std::lock_guard<std::mutex> lock(g_io_mutex);
                std::cout << "Hello" << "(" << i << ")" << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
            {
                std::lock_guard<std::mutex> lock(g_io_mutex);
                std::cout << "World" << "(" << i << ")" << std::endl;
            }
        });
    }
    return 0;
}