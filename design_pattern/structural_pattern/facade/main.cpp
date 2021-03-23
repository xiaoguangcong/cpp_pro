#include "facade.h"

int main()
{
    printf("外观模式\n");
    Facade* facade = new Facade();
    facade->operationWrapper();
    return 0;
}