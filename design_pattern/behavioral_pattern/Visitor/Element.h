#ifndef __ELEMENT_H__
#define __ELEMENT_H__

#include <iostream>
#include "Visitor.h"

using namespace std;

// 抽象元素
class Element
{
public:
    Element(){};
    virtual void accept(Visitor*) = 0;
    void setPrice(int price) {
        this->price_ = price;
    }
    int getPrice() {
        return this->price_;
    }
    void setNum(int num) {
        this->num_ = num;
    }
    int getNum() {
        return num_;
    }
    void setName(std::string name) {
        this->name_ = name;
    }
    std::string getName() {
        return name_;
    }
private: 
    int price_;
    int num_;
    std::string name_;
};

// 具体元素: Apple

class Apple :public Element
{
public:
	Apple();
	Apple(string name, int price);
	void accept(Visitor*);
};

// 具体元素: Book
class Book :public Element
{
public:
	Book();
	Book(string name, int price);
	void accept(Visitor*);
};

#endif