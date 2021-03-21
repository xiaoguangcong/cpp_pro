#pragma once

#include <iostream>

// 原型类
class Prototype {
public:
    Prototype(){};
    virtual ~Prototype(){}
    virtual Prototype* clone() = 0;
};

class ConcretePrototype : public Prototype {
public:
    ConcretePrototype(std::string str) {
        str_ = str;
    }
    ConcretePrototype(const ConcretePrototype& rhs) {
        str_ = rhs.str_;
    }
    ConcretePrototype* clone() {
        return new ConcretePrototype(*this);
    }
    void show() {
        std::cout << str_ << std::endl;
    }

private:
    std::string str_;
};

