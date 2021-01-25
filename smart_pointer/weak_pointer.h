#include "smart_pointer.h"

namespace smart_pointer
{

/* ---------- weak point ---------- */
template<typename T>
class WeakPtr
{
public:
    WeakPtr() {};

    WeakPtr(const SharedPtr<T> &p) : ptr(p.get())
    {}

    ~WeakPtr()
    {}

    WeakPtr<T>& operator=(const WeakPtr &p)
    {
        ptr = p.ptr;
        return *this;
    }

    T& operator*()
    {
        return *ptr;
    }

    T* operator->()
    {
        return ptr;
    }

    operator bool()
    {
        return ptr != nullptr;
    }

private:
    // weak point 只引用，不计数
    T *ptr;

};

/* ---------- 循环引用例子 ---------- */
class B;
class A
{
public:
    SharedPtr<B> pb;  // 类A中有指向类B的shared pointer
};

class B
{
public:
    SharedPtr<A> pa; // 类B中有指向类A的shared pointer
};

/* ---------- 打破循环引用例子 ---------- */
class D;
class C
{
public:
    C() {};
    SharedPtr<D> pd; // 类C中有指向类D的shared pointer
};

class D
{
public:
    D() {};
    WeakPtr<C> pc; // 类D中有指向类C的weak pointer
};

}; // namespace smart_pointer