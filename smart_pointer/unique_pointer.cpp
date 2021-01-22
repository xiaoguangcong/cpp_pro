//
// Created by xgc on 2021/1/22.
//

#include <iostream>

namespace smart_pointer
{

template <typename T> 
struct PointerDeleter{
    void operator()(const T *ptr) {
        if(ptr) {
            delete ptr;
            ptr = nullptr;
        }
    }
};

template <typename T, typename Deleter = PointerDeleter<T> >
class UniquePtr{
public:
    UniquePtr();
    UniquePtr(T *_ptr);
    UniquePtr(UniquePtr &&p); // 移动构造函数
    ~UniquePtr();

// non-copyable
private:
    UniquePtr(const UniquePtr &p);
    UniquePtr &operator=(const UniquePtr &p);

public:
    T& operator* ();
    T* operator-> ();
    UniquePtr &operator=(UniquePtr &&p); // 移动赋值，右值
    operator bool() const;

    // 返回原始指针
    T* get() const;
    // 返回指针，释放所有权
    T* release();
    // 替换被管理的对象
    void reset(T *_ptr);
    // 交换被管理的对象
    void swap(UniquePtr &p);

private:
    T *ptr;
};

template <typename T, typename Deleter>
UniquePtr<T, Deleter>::UniquePtr() : ptr(nullptr)
{}

template <typename T, typename Deleter>
UniquePtr<T, Deleter>::UniquePtr(T *_ptr) : ptr(_ptr)
{}

// 移交所有权
template <typename T, typename Deleter>
UniquePtr<T, Deleter>::UniquePtr(UniquePtr &&p) : ptr(p.ptr)
{
    p.ptr = nullptr;
}

// 析构函数
template<typename T, typename Deleter>
UniquePtr<T, Deleter>::~UniquePtr() 
{
    Deleter()(ptr);
    std::cout << "unique ptr destory." << std::endl;
}

// 
template<typename T, typename Deleter>
T& UniquePtr<T, Deleter>::operator*()
{
    return *ptr;
}

// 
template<typename T, typename Deleter>
T* UniquePtr<T, Deleter>::operator->()
{
    return ptr;
}

// 
template<typename T, typename Deleter>
UniquePtr<T, Deleter>& UniquePtr<T, Deleter>::operator=(UniquePtr &&p) 
{
    std::swap(ptr, p.ptr);
    return *this;
}

template<typename T, typename Deleter>
UniquePtr<T, Deleter>::operator bool() const 
{
    return ptr != nullptr;
}

template<typename T, typename Deleter>
T* UniquePtr<T, Deleter>::get() const 
{
    return ptr;
}

template<typename T, typename Deleter>
T* UniquePtr<T, Deleter>::release()
{
    T *pointer = ptr;
    ptr = nullptr;
    return pointer;
}

template<typename T, typename Deleter>
void UniquePtr<T, Deleter>::reset(T *_ptr) 
{
    UniquePtr<T, Deleter>().swap(*this);
    ptr = _ptr;
}

template<typename T, typename Deleter>
void UniquePtr<T, Deleter>::swap(UniquePtr &p) 
{
    std::swap(ptr, p.ptr);
}

}; // namespace smart_pointer