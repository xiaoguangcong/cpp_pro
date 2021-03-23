#pragma once

#include <cstdio>
#include <iostream>

// 抽象构建
class Component
{
public:
    Component(){}
    virtual void operation() = 0;
};

// 具体构建
class ConcreteComponent : public Component
{
public:
    void operation()
    {
        std::printf("ConcreteComponent\n");
    }
};

// 抽象装饰类
class Decorator : public Component
{
public:
    Decorator(){}
    Decorator(Component* c) 
    {
        this->component = c;
    }
    void operation()
    {
        this->component->operation();
    }
    void setComponent(Component* c)
    {
        this->component = c;
    }
    Component* getComponent()
    {
        return this->component;
    }
private:
    Component* component;
};

// 具体装饰类A
class DecoratorA : public Decorator
{
public:
    DecoratorA(){}
    DecoratorA(Component* c)
    {
        this->setComponent(c);
    }
    void operation()
    {
        this->getComponent()->operation();
        this->behavior();
    }
    void behavior()
    {
        printf("DecoratorA.\n");
    }
};

// 具体装饰类B
class DecoratorB : public Decorator
{
public:
    DecoratorB(){}
    DecoratorB(Component* c)
    {
        this->setComponent(c);
    }
    void operation()
    {
        this->getComponent()->operation();
        this->behavior();
    }
    void behavior()
    {
        printf("DecoratorB.\n");
    }
};

// 具体装饰类B
class DecoratorC : public Decorator
{
public:
    DecoratorC(){}
    DecoratorC(Component* c)
    {
        this->setComponent(c);
    }
    void operation()
    {
        this->getComponent()->operation();
        this->behavior();
    }
    void behavior()
    {
        printf("DecoratorC.\n");
    }
};
