#include "Context.h"

int main()
{
    printf("策略模式\n");
    printf("\n");
    Context* ctx = new Context();
    int arr[] = { 10, 23, -1, 0, 300, 87, 28, 77, -32, 2 };
    ctx->setInput(arr, sizeof(arr)/sizeof(int));
    printf("输入: ");
    ctx->print();

    // 冒泡排序
    ctx->setSortStrategy(new BubbleSort());
    ctx->sort();

    // 选择排序
    ctx->setSortStrategy(new SelectionSort());
    ctx->sort();

    // 插入排序
    ctx->setSortStrategy(new InsertSort());
    ctx->sort();

    return 0;
}