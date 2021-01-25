//
// Created by xgc on 2021/1/21.
//
#include <iostream>
#include "shared_pointer.h"
#include "weak_pointer.h"
#include "unique_pointer.h"

int main() {
    /* --------- Test the shared pointer -------- */
    std::cout << std::endl;
    std::cout << "--------- Test the shared pointer --------" << std::endl;
    smart_pointer::SharedPtr<int> shared_ptr1(new int(0));
    std::cout << "use count of shared_ptr1 is " << shared_ptr1.use_count() << std::endl;
    smart_pointer::SharedPtr<int> shared_ptr2, shared_ptr3;
    std::cout << "use count of shared_ptr2 is " << shared_ptr2.use_count() << std::endl;
    std::cout << "after run 'shared_ptr2 = shared_ptr1' " << std::endl;
    shared_ptr2 = shared_ptr1;
    std::cout << "use count of shared_ptr2 is " << shared_ptr2.use_count() << std::endl;
    smart_pointer::SharedPtr<int> shared_ptr4(shared_ptr1);
    std::cout << "after run 'shared_ptr4(shared_ptr1)' " << std::endl;
    std::cout << "use count of shared_ptr4 is " << shared_ptr4.use_count() << std::endl;
    std::cout << std::endl;
    /* --------- Test the shared pointer end -------- */

    /* --------- Test the unique pointer -------- */
    std::cout << std::endl;
    std::cout << "--------- Test the unique pointer --------" << std::endl;
    smart_pointer::UniquePtr<int> unique_ptr(new int(0));
    //smart_pointer::UniquePtr<int> unique_ptr1 = unique_ptr; // 编译不通过
    //smart_pointer::UniquePtr<int> unique_ptr2(unique_ptr);  // 编译不通过
    std::cout << "*unique_ptr: " << *unique_ptr << std::endl;

    int *unique_ptr3 = unique_ptr.release();
    if(!unique_ptr) { std::cout << "unique_ptr is released." << std::endl; }
    std::cout << "*unique_ptr3: " << *unique_ptr3 << std::endl;
    delete unique_ptr3;

    unique_ptr = smart_pointer::UniquePtr<int>(new int(1)); //移动赋值
    smart_pointer::UniquePtr<int> unique_ptr4(new int(2));
    unique_ptr4.swap(unique_ptr);

    unique_ptr.reset(new int(3));
    std::cout << "*unique_ptr: " << *unique_ptr << std::endl;
    std::cout << std::endl;
    /* --------- Test the unique pointer end -------- */

    /* --------- example of circular reference in shared pointer -------- */
    std::cout << std::endl;
    std::cout << "--------- example of circular reference in shared pointer --------" << std::endl;
    smart_pointer::SharedPtr<smart_pointer::A> shared_ptr_a(new smart_pointer::A());
    smart_pointer::SharedPtr<smart_pointer::B> shared_ptr_b(new smart_pointer::B());
    if(shared_ptr_a && shared_ptr_b) {
        shared_ptr_a->pb = shared_ptr_b;
        shared_ptr_b->pa = shared_ptr_a;
    }
    std::cout << "shared_ptr_a use count: " << shared_ptr_a.use_count() << std::endl;
    std::cout << "shared_ptr_b use count: " << shared_ptr_b.use_count() << std::endl;
    std::cout << std::endl;

    /* --------- Test the weak pointer -------- */
    std::cout << std::endl;
    std::cout << "--------- Test the weak pointer --------" << std::endl;
    smart_pointer::SharedPtr<smart_pointer::C> shared_ptr_c(new smart_pointer::C);
    smart_pointer::SharedPtr<smart_pointer::D> shared_ptr_d(new smart_pointer::D);
    if(shared_ptr_c && shared_ptr_d) {
        shared_ptr_c->pd = shared_ptr_d;
        shared_ptr_d->pc = shared_ptr_c;
    }
    std::cout << "shared_ptr_c use count: " << shared_ptr_c.use_count() << std::endl;
    std::cout << "shared_ptr_d use count: " << shared_ptr_d.use_count() << std::endl;
    std::cout << std::endl;

    return 0;
}