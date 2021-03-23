#pragma once

#include <cstdio>
#include <iostream>

class Subsystem1
{
public:
    Subsystem1(){}
    ~Subsystem1(){}
    void run() { std::printf("Subsystem1 operation.\n"); }
};

class Subsystem2
{
public:
    Subsystem2(){}
    ~Subsystem2(){}
    void operate() { std::printf("Subsystem2 operation.\n"); }
};

class Facade
{
public:
    Facade()
    {
        sub1_ = new Subsystem1();
        sub2_ = new Subsystem2();
    }
    ~Facade()
    {
        delete sub1_;
        delete sub2_;
    }
    void operationWrapper()
    {
        this->sub1_->run();
        this->sub2_->operate();
    }
private:
    Subsystem1* sub1_;
    Subsystem2* sub2_;
};
