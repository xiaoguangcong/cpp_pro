#pragma once 
#include <cstdio>
#include <iostream>

// 实现类接口
class Implementor
{
public:
    virtual void operationImpl() = 0;
};

// 具体实现类A
class ConcreteImplementorA : public Implementor
{
public:
    void operationImpl() {
        printf("ConcreteImplementorA operate!\n");
    }
};

// 具体实现类B
class ConcreteImplementorB : public Implementor
{
public:
    void operationImpl() {
        printf("ConcreteImplementorB operate!\n");
    }
};

// 抽象类
class Abstraction{
public:
    virtual void setImplementor(Implementor*) = 0;
    virtual void operate() = 0;
};

// 扩充抽象类A
class RefinedAbstraction_A : public Abstraction
{
public:
    void setImplementor(Implementor* impl) {
        impl_ = impl;
    }
    void operate() {
        impl_->operationImpl();
    }
private:
    Implementor* impl_;
};

// 扩充抽象类A
class RefinedAbstraction_B : public Abstraction
{
public:
    void setImplementor(Implementor* impl) {
        impl_ = impl;
    }
    void operate() {
        impl_->operationImpl();
    }
private:
    Implementor* impl_;
};

