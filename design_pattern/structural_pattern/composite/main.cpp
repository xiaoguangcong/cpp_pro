#include "composite.h"

int main() {
    printf("组合模式\n");
    Composite* ptr = new Composite("总部");
    ptr->add(new Leaf("总部财务部门"));
    ptr->add(new Leaf("总部人力资源部门"));
    Composite * p = new Composite("上海分部");
	p->add(new Leaf("上海分部财务部门"));
	p->add(new Leaf("上海分部人力资源部门"));
	ptr->add(p);
	ptr->display();
    return 0;
}