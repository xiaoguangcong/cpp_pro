#include "prototype.h"

int main(){
    printf("原型模式\n");
    ConcretePrototype* ptrA = new ConcretePrototype("prototype");
    ptrA->show();
    ConcretePrototype* ptrB = ptrA->clone();
    ptrB->show();
    return 0;
}