#include "builder.h"

int main(){
    //指挥者
    Director* director = new Director();
    // 产品
    Product* product;

    //指定具体建造者A
    AbstractBuilder* builderA = new ConcreteBuilderA();
    director->setBuilder(builderA);
    product = director->construct();
    product->printProductInfo();

    std::cout << std::endl;

    //指定具体建造者B
    AbstractBuilder* builderB = new ConcreteBuilderB();
    director->setBuilder(builderB);
    product = director->construct();
    product->printProductInfo();

    return 0;
}