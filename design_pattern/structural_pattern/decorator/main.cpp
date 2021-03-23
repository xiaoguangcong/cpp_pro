#include "decorator.h"

int main()
{
    printf("装饰器模式\n");
    Component* c1 = new ConcreteComponent();
    Component* decorator1 = new DecoratorA(c1);
    decorator1->operation();

    printf("\n");
    Component* c2 = new ConcreteComponent();
    Component* decorator2 = new DecoratorA(c2);
    Component* decorator3 = new DecoratorB(decorator2);
    decorator3->operation();

    printf("\n");
    Component* c4 = new ConcreteComponent();    
    Component* decorator4 = new DecoratorA(c4);
    Component* decorator5 = new DecoratorB(decorator4);
    Component* decorator6 = new DecoratorB(decorator5);
    decorator6->operation();

    return 0;
}