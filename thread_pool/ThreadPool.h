#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <iostream>
#include <mutex>
#include <queue>
#include <functional>
#include <future>
#include <thread>
#include <vector>
#include <utility>

const static int THREAD_NUM = 4;

template<typename T>
class TaskQueue
{
public:
    TaskQueue(){}
    TaskQueue(TaskQueue&& t){}
    ~TaskQueue(){}

    size_t size() {
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_task.size();
    }

    bool empty() {
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_task.empty();
    }

    void enqueue(T &t) {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_task.emplace(t);
    }

    bool dequeue(T &t) {
        std::unique_lock<std::mutex> lock(m_mutex);
        if (m_task.empty()) {
            return false;
        }
        t = std::move(m_task.front());
        m_task.pop();
        return true;
    }

private:
    std::queue<T> m_task;
    std::mutex m_mutex;
    std::condition_variable m_condition;
};

class ThreadPool
{
private:

    //  内置线程工作类
    class ThreadWorker
    {
    public:
        ThreadWorker(ThreadPool *pool, int id) : m_id(id), m_pool(pool) 
        {}

        //重载()操作
        void operator()()
        {
            // 定义基础函数类func
            std::function<void()> func;

            // 是否正在取出队列中元素
            bool dequeued;

            while (!m_pool->m_shutdown)
            {
                {
                    std::unique_lock<std::mutex> lock(m_pool->m_conditional_mutex);

                    while(m_pool->m_queue.empty()) 
                    {
                        m_pool->m_conditional_lock.wait(lock);
                    }

                    dequeued = m_pool->m_queue.dequeue(func);
                }

                // 如果成功取出，执行工作函数
                if (dequeued) {
                    func();
                }    
            }
        }

    private:
        int m_id;
        ThreadPool *m_pool;  // 所属线程池
    };

private:
    bool m_shutdown;   // 线程池是否关闭

    TaskQueue<std::function<void()>> m_queue;   // 任务队列

    std::vector<std::thread> m_threads;   // 工作线程队列

    std::mutex m_conditional_mutex;    // 线程休眠锁互斥变量

    std::condition_variable m_conditional_lock;  // 线程环境锁，可以让线程处于休眠或者唤醒状态


public:
    // 线程池构造函数
    ThreadPool() : m_shutdown(false), m_threads(std::vector<std::thread>(THREAD_NUM))
    {}

    ThreadPool(const ThreadPool &) = delete;

    ThreadPool(ThreadPool &&) = delete;

    ThreadPool &operator=(const ThreadPool &) = delete;

    ThreadPool &operator=(ThreadPool &&) = delete;

    // Inits thread pool
    void init()
    {
        for (int i = 0; i < m_threads.size(); ++i)
        {
            // 分配工作线程
            m_threads.at(i) = std::thread(ThreadWorker(this, i));
        }
    }

    // Waits until threads finish their current task and shutdowns the pool
    void shutdown()
    {
        m_shutdown = true;
        m_conditional_lock.notify_all();   // 通知，唤醒所有工作线程

        for (int i = 0; i < m_threads.size(); ++i)
        {
            // 判断线程是否在等待
            if (m_threads.at(i).joinable()) 
            {
                // 将线程加入到等待队列
                m_threads.at(i).join();
            }
        }
    }

    // Submit a function to be executed asynchronously by the pool
    template<typename F, typename... Args>
    auto submit(F &&f, Args &&...args) -> std::future<decltype(f(args...))>
    {
        // 连接函数和参数定义，特殊函数类型，避免左右值错误
        std::function<decltype(f(args...))()> func = std::bind(std::forward<F>(f), std::forward<Args>(args)...);

        auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(func);

        std::function<void()> warpper_func = [task_ptr]()
        {
            (*task_ptr)();
        };

        // 队列通用安全封包函数，并压入安全队列
        m_queue.enqueue(warpper_func);

        // 唤醒一个等待中的线程
        m_conditional_lock.notify_one();

        return task_ptr->get_future();
    }

};

#endif
