#include "sort.h"

/*
    堆排序的基本实现：
    1. 建立大根堆--将n个元素组成的无序序列构建一个大根堆，
    2. 交换堆元素--交换堆尾元素和堆首元素，使堆尾元素为最大元素；
    3. 重建大根堆--将前n-1个元素组成的无序序列调整为大根堆
    4. 重复步骤2和步骤3，直到整个序列有序
 */


 /*
    初始化建堆的时间复杂度为O(n)，排序重建堆的时间复杂度为nlog(n)，所以总的时间复杂度为O(n+nlogn)=O(nlogn)。
    因为堆排序是就地排序，空间复杂度为常数：O(1)
 */


  /*
    堆排序稳定性:
    堆排序是不稳定的算法，它不满足稳定算法的定义。
    算法稳定性 -- 假设在数列中存在a[i]=a[j]，
    若在排序之前，a[i]在a[j]前面；并且排序之后，a[i]仍然在a[j]前面。则这个排序算法是稳定的！   
   */


   /* 
    参考：https://zhuanlan.zhihu.com/p/75894663
    
    根节点下标为0，若父节点相应数组下标为i，则其左孩子相应数组下标为2*i+1，右孩子为2*i+2.
    注意：如果我们现在处理第i个序号的结点的数，
    那么他的父结点序号就是(i-1)/2，它的孩子结点就为2i+1与2i+2。
    这个容易想，右子节点如果直接除以2，得到i+1，但是2i+2-1和2i+1-1除以2可以得到i。
    根节点从0开始，则n个节点的堆，最后一个叶节点的下标为n-1，其父节点是第一个非叶节点，下标为((n-1)-1 )/ 2 = (n-2)/2 = n/2 - 1
    */

// 将i节点为根的堆中小的数依次上移,n表示堆中的数据个数
static void AdjustHeap(int arr[], int i, int length) {
    int l = 2 * i + 1;   // i的左儿子
    int r = 2 * i + 2;   // i的右儿子
    int temp = i;        // 先设置父节点和子节点三个节点中最大值的位置为父节点下标
    if (l < length && arr[l] > arr[temp]) {
        temp = l;
    }
    if (r < length && arr[r] > arr[temp]) {
        temp = r;
    }
    //最大值不是父节点，交换
    if (temp != i) {
        std::swap(arr[i], arr[temp]); 
        AdjustHeap(arr, temp, length);  //递归调用，保证子树也是最大堆
    }
}


// 建立最大堆
static void BuildMaxHeap(int* arr, int length) {
    // 从最后一个非叶子节点（n/2-1）开始自底向上构建，
    for (int i = length/2-1; i >= 0; --i) {
        AdjustHeap(arr, i, length);
    }
}

void HeapSort(int *arr, int length) {
    BuildMaxHeap(arr, length);
    for (int i = length-1; i > 0; --i) {
        // 将根节点(最大值)与数组待排序部分的最后一个元素交换,这样最终得到的是递增序列
        std::swap(arr[0], arr[i]);
        // 待排序数组长度减一,只要对换到根节点的元素进行排序，将它下沉就好了。
        AdjustHeap(arr, 0, i);
    }
}


