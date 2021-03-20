#include "simple_factory.h"
#include "factory_method.h"
#include "abstract_factory.h"
#include <cstdio>


int main (){

    printf("简单工厂模式\n");
    // 定义工厂类对象
    SimpleFactory::Factory* factory = new SimpleFactory::Factory();
    
    // 定义抽象产品
    SimpleFactory::AbstractProduct* product_a = factory->createProduct("ProductA");
    product_a->show();

    SimpleFactory::AbstractProduct* product_b = factory->createProduct("ProductB");
    product_b->show();

    printf("\n");

    printf("工厂模式\n");
    // 定义工厂类对象和产品对象
    FactoryMethod::AbstractFactory* fac = NULL;
    FactoryMethod::AbstractProduct* pro = NULL;

    fac = new FactoryMethod::FactoryA();
    pro = fac->getProduct();
    pro->show();

    fac = new FactoryMethod::FactoryB();
    pro = fac->getProduct();
    pro->show();

    printf("\n");

    printf("抽象工厂模式\n");
    // 定义工厂类对象和产品对象
    AbstractFactory::AbstractFactory* fac_ = NULL;
    AbstractFactory::AbstractBall* ball = NULL;
    AbstractFactory::AbstractShirt* shirt = NULL;

    fac_ = new AbstractFactory::BasketballFactory();
    ball = fac_->getBall();
    shirt = fac_->getShirt();
    ball->play();
    shirt->wear();

    fac_ = new AbstractFactory::FootballFactory();
    ball = fac_->getBall();
    shirt = fac_->getShirt();
    ball->play();
    shirt->wear();

    return 0;
}