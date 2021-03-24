#include "responsibility.h"
#include <cstdio>

int main()
{
    printf("责任链模式\n");
    printf("\n");
    // 请求处理者：组长，主管，经理，老板
    Approver *groudLeader, *head, *manager, *boss;
    groudLeader = new GroupLeader("组长");
    head = new Head("主管");
    manager = new Manager("经理");
    boss = new Boss("老板");

    groudLeader->addSuperior(head);
    head->addSuperior(manager);
    manager->addSuperior(boss);

    // 创建报销单
	Bill *bill1 = new Bill(1, "Jungle", 8); 
	Bill *bill2 = new Bill(2, "Lucy", 14.4);
	Bill *bill3 = new Bill(3, "Jack", 32.9);
	Bill *bill4 = new Bill(4, "Tom", 89);

    // 全部先交给组长审批
    groudLeader->handleRequest(bill1); printf("\n");
    groudLeader->handleRequest(bill2); printf("\n");
    groudLeader->handleRequest(bill3); printf("\n");
    groudLeader->handleRequest(bill4); 

    return 0;
}