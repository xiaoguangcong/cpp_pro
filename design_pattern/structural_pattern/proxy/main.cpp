#include "proxy.h"

int main()
{
    printf("代理模式\n");

    Subject* subject = new Proxy();
    subject->method();
    delete subject;
    return 0;
}