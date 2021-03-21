#pragma once
#include <iostream>
#include <string>

namespace SimpleFactory {
 
// 抽象产品类 AbstractProduct
class AbstractProduct{
public:
    virtual void show() = 0;
};

// 具体产品类A
class ProductA : public AbstractProduct {
public:
    void show() override{
        std::cout << " product a created by simple factory" << std::endl;
    };
};

// 具体产品类B
class ProductB : public AbstractProduct {
public:
    void show() override{
        std::cout << " product b created by simple factory" << std::endl;
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
 
}

