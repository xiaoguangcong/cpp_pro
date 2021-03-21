#pragma once
#include "simple_factory.h"
#include <iostream>

namespace FactoryMethod {

class AbstractProduct{
public:
    virtual void show() = 0;
};

class ProductA : public AbstractProduct {
public:
    void show() {
        std::cout << "product A created by factory method" << std::endl;
    }
};

class ProductB : public AbstractProduct {
public:
    void show() {
        std::cout << "product B created by factory method" << std::endl;
    }
};

//抽象工厂类
class AbstractFactory{
public:
    // 工厂是生产产品的
    virtual AbstractProduct* getProduct() = 0;
};

class FactoryA : public AbstractFactory {
public:
    AbstractProduct* getProduct() {
        return new ProductA();
    }
};

class FactoryB : public AbstractFactory {
public:
    AbstractProduct* getProduct() {
        return new ProductB();
    }
};

}


