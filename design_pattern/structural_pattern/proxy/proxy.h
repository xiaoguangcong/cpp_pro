#pragma once
#include <cstdio>
#include <ctime>
#include <iostream>
#include <memory>

/*
    实例：
    在某应用软件中需要记录业务方法的调用日志，
    在不修改现有业务的基础上位每个类提供一个日志记录代理类，在代理类中输出日志，
    例如在业务方法method()调用之前输出“方法method()被调用，调用时间为2019-10-28 07:33:30”，
    调用之后输出“方法method()”调用成功。在代理类中调用真实业务类的业务方法，使用代理模式设计该日志记录模块的结构。
 */

// 抽象主题角色
class Subject
{
public:
    Subject(){}
    virtual void method() = 0;
};

// 真实主题角色
class RealSubject : public Subject
{
public:
    RealSubject(){}
    void method()
    {
        std::printf("调用业务方法\n");
    }
};

// Log类
class Log
{
public:
    Log(){}
    std::string getTime()
    {
        time_t t = time(NULL);
        char ch[64] = { 0 };
        //年-月-日 时:分:秒
        strftime(ch, sizeof(ch)-1, "%Y-%m-%d %H:%M:%S", localtime(&t));
        return ch;
    }
};

class Proxy : public Subject
{
public:
    Proxy()
    {
        realSubject_ = new RealSubject();
        log_ = new Log();
    }
    void preCallMethod()
    {
        printf("方法method()被调用，调用时间为%s\n", log_->getTime().c_str());
    }
    void method()
    {
        preCallMethod();
        realSubject_->method();
        postCallMethod();
    }
    void postCallMethod()
    {
        printf("方法method()调用调用成功!\n");
    }
private:
    RealSubject* realSubject_;
    Log* log_;
};