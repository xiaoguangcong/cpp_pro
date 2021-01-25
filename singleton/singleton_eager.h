#include <iostream>

/***
 * 饿汉式的方法是程序启动时就创建一个唯一的实例对象。
 * 优点：简单
 * 缺点：可能会导致进程启动慢，且如果有多个单例类对象实例启动顺序不确定。
 * 适用范围： 如果这个单例对象在多线程高并发环境下频繁使用，性能要求较高，那么显然使用饿汉模式来避免资源竞争，提高响应速度更好。
 * 实现：
    1. 构造函数私有   
    2. 定义一个私有静态成员变量，类型为当前类类型 
    3. 在类外通过构造函数初始化  
    4. 防拷贝：拷贝构造定义成私有，只声明不实现，或者定义为delete函数
    5. 定义一个static共有的成员函数，函数内部返回单例，返回值类型为引用/指针
 ***/

namespace singleton 
{
    
class SingletonEager
{
public:
    static SingletonEager* get_instance() {
        return &instance;
    }

private:
    static SingletonEager instance;

    // 构造函数私有，禁止拷贝、赋值
    SingletonEager() {};
    SingletonEager(const SingletonEager&) = delete;
    SingletonEager& operator=(const SingletonEager&) = delete;
};

SingletonEager SingletonEager::instance; // 在程序入口之前就完成单例对象的初始化

};