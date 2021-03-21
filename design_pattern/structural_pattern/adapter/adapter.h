#include <iostream>

// *** 类适配器 *** //

// 被适配的类
class Adaptee {
public:
    Adaptee(){}
    void specificRequest() {
        std::cout << "request by adaptee. " << std::endl;
    }
};

// 客户调用的
class Target{
public:
    virtual void request() = 0;
};

// 适配器
class Adapter : public Target, public Adaptee {
public:
    void request() {
        this->specificRequest();
    }
};

// *** 对象适配器 *** //
class AdapterByObject : public Target{
public:
    void request() {
       adaptee_->specificRequest();
    }
private:
    Adaptee* adaptee_;
};