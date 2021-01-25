//
// Created by xgc on 2021/1/21.
//

#include "smart_pointer.h"

namespace smart_pointer
{

template<typename T>
class SharedPtr
{
public:
    explicit SharedPtr();
    explicit SharedPtr(T *_ptr);
    SharedPtr(const SharedPtr& p);  // 拷贝构造函数
    ~SharedPtr();

    // 拷贝赋值运算符(左边的值减少，右边的值增加)
    SharedPtr& operator=(const SharedPtr& p);

    // 解引用运算符
    T& operator*();
    // 箭头运算符
    T* operator->();
    // 重载布尔值操作
    operator bool();

    T* get() const;

    size_t use_count();

    bool unique();

    void swap(SharedPtr& p);

private:
    size_t *count;
    T *ptr;
};

template<typename T>
SharedPtr<T>::SharedPtr() : count(new size_t(0)), ptr(nullptr)
{}

template<typename T>
SharedPtr<T>::SharedPtr(T *_ptr) : count(new size_t(1)), ptr(_ptr)
{}

template<typename T>
SharedPtr<T>::~SharedPtr()
{
    --(*count);
    if(*count <= 0) {
        delete ptr;
        delete count;
        ptr = nullptr;
        count = nullptr;
    }
    std::cout << "shared ptr destory." << std::endl;
}

template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr &p)
{
    count = p.count;
    ptr = p.ptr;
    ++(*count);
}

template<typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr &p)
{
    // 如果是原指针，直接返回
    if(ptr == p.ptr) {
        return *this;
    }

    if(ptr) {
        --(*count);
        if((*count) == 0) {
            delete ptr;
            delete count;
        }
    }

    ptr = p.ptr;
    count = p.count;
    ++(*count);
    return *this;
}

template<typename T>
T& SharedPtr<T>::operator*()
{
    return *ptr;
}

template<typename T>
T* SharedPtr<T>::operator->()
{
    return ptr;
}

template<typename T>
SharedPtr<T>::operator bool()
{
    return ptr != nullptr;
}

template<typename T>
T* SharedPtr<T>::get() const
{
    return ptr;
}

template<typename T>
size_t SharedPtr<T>::use_count()
{
    return *count;
}

template<typename T>
bool SharedPtr<T>::unique()
{
    return *count == 1;
}

template<typename T>
void SharedPtr<T>::swap(SharedPtr& p)
{
    std::swap(*this, p);
}

}; //namespace smart_pointer