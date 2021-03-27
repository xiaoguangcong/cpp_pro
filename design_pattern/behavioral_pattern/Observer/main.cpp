#include "Observer.h"

int main()
{
    printf("观察者模式\n");
    printf("\n");
    Subject* sub = new ConcreteSubject();
    Observer* obsA = new ConcreteObserverA();
    Observer* obsB = new ConcreteObserverB();
    sub->attach(obsA);
    sub->attach(obsB);
    sub->notify();
    sub->detach(obsA);
    sub->notify();
    return 0;
}