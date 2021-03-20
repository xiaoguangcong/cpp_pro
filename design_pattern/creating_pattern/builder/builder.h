#pragma once

#include <cstdio>
#include <iostream>

/*
    建造者模式：
    将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示。
 */ 


// 产品：最终要建成的东西
class Product{
public:
    Product(){}
    void setSize(int size){
        size_ = size;
    }
    void setColor(std::string color){
        color_ = color;
    }
    void printProductInfo(){
        std::cout << "Product info: " << std::endl;
        std::cout << "size: " << size_ << std::endl;
        std::cout << "color: " << color_ << std::endl;
    }
private:
    int size_;   // 产品大小
    std::string color_;  // 产品颜色
};


//抽象建造者AbstractBuilder
class AbstractBuilder{
public:
    AbstractBuilder(){
        product = new Product();
    }

    virtual void setSize() = 0;
    virtual void setColor() = 0;
    virtual Product* getProduct() = 0;

    Product* product;
};


//具体建造者ConcreteBuilderA
class ConcreteBuilderA : public AbstractBuilder {
public:
    ConcreteBuilderA(){
        printf("ConcreteBuilderA:\n");
    }
    void setSize(){
        this->product->setSize(5);
        printf("ConcreteBuilderA set product size: 5.\n");
    }
    void setColor(){
        this->product->setColor("red");
        printf("ConcreteBuilderA set product color: red.\n");
    }
    Product* getProduct(){
        return this->product;
    }
};

//具体建造者ConcreteBuilderA
class ConcreteBuilderB : public AbstractBuilder {
public:
    ConcreteBuilderB(){
        printf("ConcreteBuilderB:\n");
    }
    void setSize(){
        this->product->setSize(10);
        printf("ConcreteBuilderB set product size: 10.\n");
    }
    void setColor(){
        this->product->setColor("yellow");
        printf("ConcreteBuilderB set product color: yellow.\n");
    }
    Product* getProduct(){
        return this->product;
    }
};


//指挥者Director
class Director{
public:
    Director(){}

    void setBuilder(AbstractBuilder* builder) {
        builder_ = builder;
    }

    //封装组装流程，返回建造结果
    Product* construct(){
        builder_->setSize();
        builder_->setColor();
        return builder_->getProduct();
    }

private:
    AbstractBuilder* builder_;
};