//
// Created by xgc on 2021/1/21.
//
# pragma once

#include <stdio.h>
#include <iostream>

template<typename T>
class SharedPtr
{
private:
    size_t *count;
    T *ptr;
public:
    // 构造函数
    SharedPtr() : count(new size_t), ptr(nullptr)
    {}

    explicit SharedPtr(T *ref_ptr) : count(new size_t), ptr(ref_ptr)
    {
        *count = 1;
    }

    // 析构函数
    ~SharedPtr()
    {
        --(*count);
        if(0 == *count) {
            delete ptr;
            delete count;
            ptr = nullptr;
            count = nullptr;
        }
    }

    // 拷贝构造函数
    SharedPtr(const SharedPtr& share_ptr)
    {
        count = share_ptr.count;
        ptr = share_ptr.ptr;
        ++(*count);
    }

    // 移动构造函数
    SharedPtr(SharedPtr&& share_ptr) : ptr(share_ptr.ptr), count(share_ptr.count)
    {
        ++(*count);
    }

    // 拷贝赋值运算符
    void operator=(const SharedPtr& share_ptr) {
        SharedPtr(std::move(share_ptr));
    }

    // 移动赋值运算符
    void operator=(const SharedPtr&& share_ptr) {
        SharedPtr(std::move(share_ptr));
    }

    // 解引用运算符
    T& operator*() {
        return *ptr;
    }

    // 箭头运算符
    T* operator->() {
        return ptr;
    }

    // 重载布尔值操作
    operator bool() {
        return ptr == nullptr;
    }

    T* get() {
        return ptr;
    }

    size_t use_count() {
        return *count;
    }

    bool unique() {
        return *count == 1;
    }

    void swap(SharedPtr& share_ptr) {
        std::swap(*this, share_ptr);
    }
};
