#include "sort.h"

/*
    快速排序算法是一种基于交换的高效的排序算法，它采用了 分治法 的思想：
    1、从数列中取出一个数作为基准数（枢轴，pivot）。 
    2、将数组进行划分(partition)，将比基准数大的元素都移至枢轴右边，将小于等于基准数的元素都移至枢轴左边。
    3、再对左右的子区间重复第二步的划分操作，直至每个子区间只有一个元素。

 */

 /*
    快速排序的时间复杂度在最坏情况下是O(N2)，平均的时间复杂度是O(N*lgN)。

    这句话很好理解：假设被排序的数列中有N个数。遍历一次的时间复杂度是O(N)，需要遍历多少次呢？至少lg(N+1)次，最多N次。
    1. 为什么最少是lg(N+1)次？快速排序是采用的分治法进行遍历的，将它看作一棵二叉树，它需要遍历的次数就是二叉树的深度，
    而根据完全二叉树的定义，它的深度至少是lg(N+1)。因此，快速排序的遍历次数最少是lg(N+1)次。
    2. 为什么最多是N次？这个应该非常简单，还是将快速排序看作一棵二叉树，它的深度最大是N。因此，快读排序的遍历次数最多是N次。
  */

  /*
    快速排序稳定性
    快速排序是不稳定的算法，它不满足稳定算法的定义。
    算法稳定性 -- 假设在数列中存在a[i]=a[j]，
    若在排序之前，a[i]在a[j]前面；并且排序之后，a[i]仍然在a[j]前面。则这个排序算法是稳定的！   
   */


static int GetPartition(int arr[], int left, int right) {
    int i = left + 1;
    int j = right;
    int temp = arr[left];

    while (i <= j) {
        while (arr[i] < temp) {
            ++i;
        }
        while (arr[j] > temp) {
            --j;
        }
        if (i < j) {
            // arr[i]比temp大，arr[j]比temp小，所以arr[i]比arr[j]大;
            std::swap(arr[i++], arr[j--]);
        } else {
            // i>=j，可以直接退出循环
            break;
        }
    }
    std::swap(arr[left], arr[j]);
    return j;
}


extern void QuickSort(int arr[], int left, int right) {
    if (left > right)
        return;
    int j = GetPartition(arr, left, right);
    QuickSort(arr, left, j-1);
    QuickSort(arr, j+1, right);
}
