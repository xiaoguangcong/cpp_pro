#pragma once
#include "simple_factory.h"
#include <iostream>

/*
    工厂方法模式：
    定义一个用于创建对象的接口，但是让子类决定将哪一个类实例化。工厂方法模式让一个类的实例化延迟到其子类。

    优点：
    1. 工厂方法用于创建客户所需产品，同时向客户隐藏某个具体产品类将被实例化的细节，用户只需关心所需产品对应的工厂；
    2. 工厂自主决定创建何种产品，并且创建过程封装在具体工厂对象内部，多态性设计是工厂方法模式的关键；
    3. 新加入产品时，无需修改原有代码，增强了系统的可扩展性，符合开闭原则。

    缺点：
    1. 添加新产品时需要同时添加新的产品工厂，系统中类的数量成对增加，增加了系统的复杂度，更多的类需要编译和运行，增加了系统的额外开销；
    2. 工厂和产品都引入了抽象层，客户端代码中均使用的抽象层（AbstractFactory和AbstractSportProduct ），增加了系统的抽象层次和理解难度。

 */

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


