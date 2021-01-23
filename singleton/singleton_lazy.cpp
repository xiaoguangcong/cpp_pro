#include <iostream>
#include <memory>
#include <mutex>

// 懒汉式(Lazy-Initialization)的方法是直到使用时才实例化对象，也就说直到调用get_instance() 方法的时候才 new 一个单例的对象。
// 好处是如果被调用就不会占用内存。

namespace singleton 
{

/***
 * 
 * 方法一：使用智能指针管理资源和锁
 * 
 * 优点：1. 基于 shared_ptr, 用了C++比较倡导的 RAII思想，用对象管理资源,当 shared_ptr 析构的时候，new 出来的对象也会被 delete掉。以此避免内存泄漏。
 *       2. 加了锁，使用互斥量来达到线程安全。这里使用了两个 if判断语句的技术称为双检锁；好处是，只有判断指针为空的时候才加锁，避免每次调用 get_instance的方法都加锁，锁的开销毕竟还是有点大的。
 * 
 * 缺点：使用智能指针会要求用户也得使用智能指针，非必要不应该提出这种约束; 使用锁也有开销; 同时代码量也增多了，实现上我们希望越简单越好。
 * 
 ***/
    
class SingletonLazy
{
public:
    // 使用智能指针，解决内存泄漏的问题
    typedef std::shared_ptr<SingletonLazy> Ptr;

    // 析构函数
    ~SingletonLazy() {
        std::cout << "---- SingletonLazy destructor called! ----" << std::endl;
    }

    // 禁用拷贝复制和赋值函数，满足单例的要求
    SingletonLazy(const SingletonLazy &) = delete;
    SingletonLazy& operator=(const SingletonLazy&) = delete;

    static Ptr get_instance() {
        // double check, 线程安全
        if (nullptr == m_instance_ptr) {
            std::lock_guard<std::mutex> lk(m_mutex);
            if (nullptr == m_instance_ptr) {
                m_instance_ptr = std::shared_ptr<SingletonLazy>(new SingletonLazy);
            }
        }
        return m_instance_ptr;
    }

private:
    SingletonLazy() {
        std::cout << "---- SingletonLazy constructor called! ----" << std::endl;
    }
    static Ptr m_instance_ptr;
    static std::mutex m_mutex; // 加锁，线程安全
};

// 在类外初始化static成员变量(注意：无法在类内部初始化)
SingletonLazy::Ptr SingletonLazy::m_instance_ptr = nullptr;
std::mutex SingletonLazy::m_mutex;

/***
 * 
 * 方法二：基于Magic Staic的方法达到线程安全(最推荐)
 * 
 * 优点：1. 通过局部静态变量的特性保证了线程安全；
 *       2. 不需要使用共享指针，代码简洁；
 *       3. 注意在使用的时候需要声明单例的引用 LazySingleton& 才能获取对象。
 * 
 ***/

class LazySingleton
{
public:
    ~LazySingleton() {
        std::cout << "---- LazySingleton destructor called! ----" << std::endl;
    }
    LazySingleton(const LazySingleton&) = delete;
    LazySingleton& operator=(const LazySingleton&) = delete;
    static LazySingleton& get_instance() {
        // 局部静态变量
        static LazySingleton instance;
        return instance;
    }

private:
    LazySingleton() {
        std::cout << "---- LazySingleton constructor called! ----" << std::endl;
    }
};

};