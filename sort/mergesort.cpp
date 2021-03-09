#include "sort.h"

/*
    归并排序，分治法的典型代表: 将原问题分解了几个子问题，解决子问题，再合并子问题的解，
    这样就得到了原问题的解。
    分治本质上就是把原问题分解为几个子问题来解决。
    快速排序也是分治思想来解决。
 */

/*
    归并排序(merge-sort):
    1. 把一个待排序的数组分解为两个子数组；
    2. 对两个子数组进行排序（通过递归地调用自己来实现）;
    3. 对两个已经排序的数组进行合并。
 */

 /*
    分析：
    1. 一个数组一直分解下去，只到分解成只包含一个元素的子数组为止, 此时自然是有序的；
    2. 归并排序的重点在于合并，而不是对子数组的排序。（快速排序与它恰恰相反，快速排序的
    重点是对子数组进行排序，而不是合并，因为它不需要合并了）
 */


 /*
    归并排序的时间复杂度是O(nlogn)，每次合并操作的平均时间复杂度为O(n)，而完全二叉树的深度为|log2n|。总的平均时间复杂度为O(nlogn)。
    空间复杂度是O(n)，是稳定排序
  */

/*
    参考： https://zhuanlan.zhihu.com/p/74820690
 */

void Merge(int* arr, int left, int right, int mid) {
    //left为第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
    //mid+1为第2有序区第1个元素，j指向第1个元素
    int i = left, j = mid + 1, k = 0;
    int *temp = new int[right - left + 1];
    while(i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid)//若比较完之后，第一个有序区仍有剩余，则直接复制到t数组中
        temp[k++]=arr[i++];
    while(j <= right)//同上
        temp[k++]=arr[j++];
    for(i = left, k = 0; i <= right; ++i, ++k) {
        arr[i] = temp[k];
    }
    delete [] temp;
}

void MergeSort(int *arr, int left, int right) {
    // 终止递归的条件，子序列长度为1
    if (left >= right) return;
    int mid = (left + right)/2;
    // 对左半边递归
    MergeSort(arr, left, mid);
    // 对右半边递归
    MergeSort(arr, mid+1, right);
    // 合并
    Merge(arr, left, right, mid);
 }



