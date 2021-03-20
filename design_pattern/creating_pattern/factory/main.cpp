#include "simple_factory.h"


int main (){
    printf("简单工厂模式\n");

    // 定义工厂类对象
    Factory* factory = new Factory();
    
    // 定义抽象产品对
    AbstractProduct* product_a = factory->createProduct("ProductA");
    product_a->show();

    AbstractProduct* product_b = factory->createProduct("ProductB");
    product_b->show();
    return 0;
}