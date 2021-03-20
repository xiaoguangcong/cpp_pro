#pragma once
#include <iostream>

/*
    抽象工厂模式：

    提供一个创建一系列相关或相互依赖对象的接口，而无需指定他们具体的类。
    简言之，一个工厂可以提供创建多种相关产品的接口，而无需像工厂方法一样，为每一个产品都提供一个具体工厂。 

 */ 

namespace AbstractFactory {

// 抽象球类
class AbstractBall{
public:
    virtual void play() = 0;
};

// 篮球
class Basketball : public AbstractBall {
public:
    void play() {
        std::cout << "Play basketball" << std::endl;
    }
};

// 足球
class Football : public AbstractBall {
public:
    void play() {
        std::cout << "Play football" << std::endl;
    }
};

// 抽象T Shirt
class AbstractShirt{
public:
    virtual void wear() = 0;
};

// 篮球T Shirt
class BasketballShirt : public AbstractShirt {
public:
    void wear() {
        std::cout << "wear basketball shirt" << std::endl;
    }
};

// 足球T Shirt 
class FootballShirt : public AbstractShirt {
public:
    void wear() {
        std::cout << "wear football shirt" << std::endl;
    }
};


//抽象工厂类
class AbstractFactory {
public:
    virtual AbstractBall* getBall() = 0;
    virtual AbstractShirt* getShirt() = 0;
};

//具体工厂类BasketballFactory
class BasketballFactory : public AbstractFactory{
public:
    AbstractBall* getBall() {
        return new Basketball();
    }

    AbstractShirt* getShirt() {
        return new BasketballShirt();
    }
};

//具体工厂类FootballFactory
class FootballFactory : public AbstractFactory{
public:
    AbstractBall* getBall() {
        return new Football();
    }

    AbstractShirt* getShirt() {
        return new FootballShirt();
    }
};

}