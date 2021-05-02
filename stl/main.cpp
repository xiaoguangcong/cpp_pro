//  参照 《stl源码解析》

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

template<class T>
struct display 
{
    void operator()(const T& x) const {
        cout << x << ' ';
    }
};

struct even 
{
    bool operator()(int x) const {
        return x % 2 ? false : true;
    }
};

class even_by_two 
{
public:
    int operator()()const {
        return _x += 2;
    }
private:
    static int _x;
};

int even_by_two::_x = 0;

int main() {
    
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8};
    vector<int> iv(ia, ia+sizeof(ia)/sizeof(int));

    cout << endl;

    // 找出iv中相邻元素值相等的第一个元素
    cout << *adjacent_find(iv.begin(), iv.end())
         << endl;    // 6

    // 找出iv中相邻元素值相等的第一个元素
    cout << *adjacent_find(iv.begin(), iv.end(), equal_to<int>())
         << endl;    // 6

    // 找出iv中元素值为6的元素个数
    cout << count(iv.begin(), iv.end(), 6)
         << endl;    // 3

    // 找出iv中元素值小于7的元素个数
    cout << count_if(iv.begin(), iv.end(), bind2nd(less<int>(), 7))
         << endl;    // 9

    // 找出iv中元素值为4的第一个元素的所在位置的值
    cout << *find(iv.begin(), iv.end(), 4)
         << endl;    // 4

    // 找出iv中元素值大于2的第一个元素的所在位置的值
    cout << *find_if(iv.begin(), iv.end(), bind2nd(greater<int>(), 2))
         << endl;    // 3

    // 找出iv中子序列iv2所出现的最后一个位置（再往后3个位置的值）
    vector<int> iv2(ia+6, ia+8);     // {6, 6}
    cout << *(find_end(iv.begin(), iv.end(), iv2.begin(), iv2.end())+3)
         << endl;    // 8

    // 找出iv中子序列iv2所出现的第一个位置（再往后3个位置的值）
    cout << *(find_first_of(iv.begin(), iv.end(), iv2.begin(), iv2.end())+3)
         << endl;    // 7


    // 遍历整个iv区间，对每一个元素执行display操作
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl;  // iv : 0 1 2 3 4 5 6 6 6 7 8

    // 迭代遍历整个iv2区间，对每个元素实行even_by_two操作（改变元素值）
    generate(iv2.begin(), iv2.end(), even_by_two());
    for_each(iv2.begin(), iv2.end(), display<int>());
    cout << endl;   // iv : 2 4

    // 迭代遍历指定区间（起点与长度），对每个元素实行event_by_two操作
    generate_n(iv.begin(), 3, even_by_two());
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl;   // iv : 6 8 10 3 4 5 6 6 6 7 8

    // 删除元素6，尾端可能有残余数据（可以容器之erase函数去除）
    remove(iv.begin(), iv.end(), 6);
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl;   // iv : 8 10 3 4 5 7 8 6 6 7 8 （最后的 6 6 7 8 是残余数据）

    // 删除元素6，结果置于另一个空间
    vector<int> iv3(12);
    remove_copy(iv.begin(), iv.end(), iv3.begin(), 6);
    for_each(iv3.begin(), iv3.end(), display<int>());
    cout << endl;   // iv3 : 8 10 3 4 5 7 8 7 8 0 0 0  （最后 0 0 0是残余数据）

    // 删除小于6的元素，结果可能有残余数据
    remove_if(iv.begin(), iv.end(), bind2nd(less<int>(), 6));
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl;   // iv : 8 10 7 8 6 6 7 8 6 7 8  （最后的 6 7 8 是残余数据）

    // 删除小于7的元素，结果置于另一个空间
    remove_copy_if(iv.begin(), iv.end(), iv3.begin(), bind2nd(less<int>(), 7));
    for_each(iv3.begin(), iv3.end(), display<int>());
    cout << endl;   // iv3 : 8 10 7 8 7 8 7 8 8 0 0 0  （最后 8 0 0 0是残余数据）

    // 将所有的元素值6，改为元素值3
    replace(iv.begin(), iv.end(), 6, 3);
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl;   // iv : 8 10 7 8 3 3 7 8 3 7 8  
    
    // 将所有的元素值3改成5，结果置于另一个空间
    replace_copy(iv.begin(), iv.end(), iv3.begin(), 3, 5);
    for_each(iv3.begin(), iv3.end(), display<int>());
    cout << endl;   // iv3 : 8 10 7 8 5 5 7 8 5 7 8 0  （最后 0 是残余数据）

    // 将所有小于5的元素值，改成元素值2
    replace_if(iv.begin(), iv.end(), bind2nd(less<int>(), 5), 2);
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl;   // iv : 8 10 7 8 2 2 7 8 2 7 8  

    // 将所有等于8的元素值，改为元素9，结果置于另一个空间
    replace_copy_if(iv.begin(), iv.end(), iv3.begin(), bind2nd(equal_to<int>(), 8), 9);
    for_each(iv3.begin(), iv3.end(), display<int>());
    cout << endl;   // iv3 : 9 10 7 9 2 2 7 9 2 7 9 0  （最后 0 是残余数据）

    // 逆向重排每一个元素
    reverse(iv.begin(), iv.end());
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl;   // iv : 8 7 2 8 7 2 2 8 7 10 8

    // 逆向重排每一个元素, 结果置于另一个空间
    reverse_copy(iv.begin(), iv.end(), iv3.begin());
    for_each(iv3.begin(), iv3.end(), display<int>());
    cout << endl;   // iv3 : 8 10 7 8 2 2 7 8 2 7 8 0 （最后 0 是残余数据）

    // 旋转（互换元素）[first, middle) 和 [middle, lase)
    rotate(iv.begin(), iv.begin()+4, iv.end());
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl;   // iv : 7 2 2 8 7 10 8 8 7 2 8

    // 旋转（互换元素）[first, middle) 和 [middle, lase)，结果置于另一个空间
    rotate_copy(iv.begin(), iv.begin()+5, iv.end(), iv3.begin());
    for_each(iv3.begin(), iv3.end(), display<int>());
    cout << endl;   // iv3 : 10 8 8 7 2 8 7 2 2 8 7 0 （最后 0 是残余数据）

    // 查找某个子序列的第一次出现地点
    int ia2[3] = {2, 8};
    vector<int> iv4(ia2, ia2+2); // {2, 8};
    cout << *search(iv.begin(), iv.end(), iv4.begin(), iv4.end())
         << endl;    // 2
    
    // 查找连续出现2个8的子序列起点
    cout << *search_n(iv.begin(), iv.end(), 2, 8) << endl;   // 8

    // 查找连续出现3个小于8的子序列起点
    cout << *search_n(iv.begin(), iv.end(), 3, 8, less<int>()) << endl;  // 7

    // 将两个区间内的元素互换，第二区间的元素不应小于第一区间的元素个数
    swap_ranges(iv4.begin(), iv4.end(), iv.begin());
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl;   // iv : 2 8 2 8 7 10 8 8 7 2 8
    for_each(iv4.begin(), iv4.end(), display<int>());
    cout << endl;   // iv4 : 7 2

    // 改变区间的值，全部减2
    transform(iv.begin(), iv.end(), iv.begin(), bind2nd(minus<int>(), 2));
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl;   // iv : 0 6 0 6 5 8 6 6 5 0 6

    // 改变区间的值，令第二区间的元素值加到第一区间的对应元素上
    // 第二区间的元素个数不应小于第一区间的元素个数
    transform(iv.begin(), iv.end(), iv.begin(), iv.begin(), plus<int>());
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl;   // iv : 0 12 0 12 10 16 12 12 10 0 12

    // *******************************

    vector<int> iv5(ia, ia+sizeof(ia)/sizeof(int));
    vector<int> iv6(ia+4, ia+8);
    vector<int> iv7(15);

    for_each(iv5.begin(), iv5.end(), display<int>());
    cout << endl;   // iv5 : 0, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8
    for_each(iv6.begin(), iv6.end(), display<int>());
    cout << endl;   // iv6 : 4, 5, 6, 6

    cout << *max_element(iv5.begin(), iv5.end()) << endl;   // 8
    cout << *min_element(iv5.begin(), iv5.end()) << endl;   // 0

    // 判断是否iv6中的元素都出现在iv5中
    // 注意：两个序列都必须是sorted ranges
    cout << includes(iv5.begin(), iv5.end(), iv6.begin(), iv6.end())
         << endl;     // 1 true

    // 将两个序列合并成一个
    // 注意：两个序列都必须是sorted ranges，合并成的结果也是sorted
    merge(iv5.begin(), iv5.end(), iv6.begin(), iv6.end(), iv7.begin());
    for_each(iv7.begin(), iv7.end(), display<int>());
    cout << endl;   // iv7 : 0 1 2 3 4 4 5 5 6 6 6 6 6 7 8

    // 符合条件的元素放在容器前段，不符合的元素放在后段
    // 不保证保留原相对次序
    partition(iv7.begin(), iv7.end(), even());
    for_each(iv7.begin(), iv7.end(), display<int>());
    cout << endl;   // iv7 : 0 8 2 6 4 4 6 6 6 6 5 5 3 7 1

    // 去除“连续重复”元素
    // 注意：结果可能有残余数据
    unique(iv5.begin(), iv5.end());
    for_each(iv5.begin(), iv5.end(), display<int>());
    cout << endl;   // iv5 : 0, 1, 2, 3, 4, 5, 6, 7, 8, 7 ,8 (最后的 7 8 是残余数据)

    // 去除“连续重复”数据，结果放在另一处
    unique_copy(iv5.begin(), iv5.end(), iv7.begin());
    for_each(iv7.begin(), iv7.end(), display<int>());
    cout << endl;   // iv7 :  0, 1, 2, 3, 4, 5, 6, 7, 8, 7 ,8, 5, 3, 7, 1 (最后的 7 8 5 3 7 1是残余数据)


    return 0;
}