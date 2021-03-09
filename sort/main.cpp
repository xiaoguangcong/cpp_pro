#include "sort.h"


void PrintArray(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int NUM = 10;
    int array[NUM] = { 0 };
    srand((unsigned int)time(nullptr));
    for (int i = 0; i < NUM; i++)
    {
        array[i] = rand() % 100 + 1;
    }
    std::cout << "快速排序示例：" << std::endl;
    std::cout << "排序前：" << std::endl;
    PrintArray(array, NUM);
    std::cout << "排序后：" << std::endl;
    QuickSort(array, 0, NUM - 1);
    PrintArray(array, NUM);

    return 0;

}