#include "bridge.h"

int main(){
    printf("桥接模式\n");
    Implementor* impl_a = new ConcreteImplementorA();
    Abstraction* abstraction_a = new RefinedAbstraction_A();
    abstraction_a->setImplementor(impl_a);
    abstraction_a->operate();

    Implementor* impl_b = new ConcreteImplementorB();
    Abstraction* abstraction_b = new RefinedAbstraction_B();
    abstraction_b->setImplementor(impl_b);
    abstraction_b->operate();

    abstraction_a->setImplementor(impl_b);
    abstraction_a->operate();

    abstraction_b->setImplementor(impl_a);
    abstraction_b->operate();

    return 0;
}