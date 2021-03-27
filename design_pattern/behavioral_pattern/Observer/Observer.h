#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include <iostream>
#include <list>
// 抽象观察者
class Observer
{
public:
    // 声明响应更新的方法
    virtual void update() = 0;
};

// 具体观察者A
class ConcreteObserverA : public Observer
{
public:
    // 实现响应的方法
    void update()
    {
        printf("具体观察者A进行更新\n");
    }
};

// 具体观察者B
class ConcreteObserverB : public Observer
{
public:
    // 实现响应的方法
    void update()
    {
        printf("具体观察者B进行更新\n");
    }
};

// 抽象目标
class Subject
{
public:
    // 添加观察者
    void attach(Observer* obs) { obsList_.push_back(obs); }
    // 移除观察者
    void detach(Observer* obs) { obsList_.remove(obs); }
    // 声明通知方法
    virtual void notify() = 0;
protected:
    std::list<Observer*> obsList_;
};

// 具体目标
class ConcreteSubject : public Subject
{
public:
    // 实现通知方法
    void notify()
    {
        for (auto it = obsList_.begin(); it != obsList_.end(); it++) {
            (*it)->update();
        }
    }
};

#endif
