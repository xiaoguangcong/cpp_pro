#include "adapter.h"

int main(){
    printf("适配器模式\n");

    printf("1. 类适配器模式：\n");    
    Target* target = new Adapter();
    target->request();

    printf("2. 对象适配器模式：\n");    
    Target* target_ = new AdapterByObject();
    target_->request();

    return 0;
}