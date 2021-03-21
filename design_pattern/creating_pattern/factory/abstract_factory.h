#pragma once
#include <iostream>

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