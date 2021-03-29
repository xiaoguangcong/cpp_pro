#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include "Strategy.h"

// 上下文类
class Context
{
public:
    Context() {
        arr_ = NULL;
        N_ = 0;
    }
    Context(int* arr, int N) : arr_(arr), N_(N) {}
    void setSortStrategy(Strategy* strategy) { sortStrategy_ = strategy; }
    void sort()
    {
        this->sortStrategy_->sort(arr_, N_);
        printf("输出： ");
        this->print();
    }
    void setInput(int* arr, int N) {
        arr_ = arr;
        N_ = N;
    }
    void print() {
        for (int i = 0; i < N_; ++i) {
            printf("%3d ", arr_[i]);
        }
        printf("\n");
    }
private:
    Strategy* sortStrategy_;
    int* arr_;
    int N_;
};

#endif