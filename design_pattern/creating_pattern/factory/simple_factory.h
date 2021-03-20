#pragma once
#include <iostream>
#include <string>

/*
    简单工厂模式：
    定义一个简单工厂类，它可以根据参数的不同返回不同类的实例，被创建的实例通常都具有共同的父类
 */

// 抽象产品类 AbstractProduct
class AbstractProduct{
public:
    virtual void show() = 0;
};

// 具体产品类A
class ProductA : public AbstractProduct {
public:
    void show() override{
        std::cout << " product a " << std::endl;
    };
};

// 具体产品类B
class ProductB : public AbstractProduct {
public:
    void show() override{
        std::cout << " product b " << std::endl;
    };
};

// 工厂
class Factory {
public:
    AbstractProduct* createProduct(std::string product_name) {
        AbstractProduct* pro = NULL;
        if (product_name == "ProductA") {
            pro = new ProductA();
        }
        else if (product_name == "ProductB") {
            pro = new ProductB();
        }
        return pro;
    }
};