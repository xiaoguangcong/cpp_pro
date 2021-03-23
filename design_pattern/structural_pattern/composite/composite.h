#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class Component
{
public:
    Component(std::string str) {
        strName_ = str;
    }
    virtual void add(Component* p) = 0;
    virtual void remove(Component* p) = 0;
    virtual void display() = 0;
protected:
    std::string strName_;
};

class Leaf : public Component
{
public:
    Leaf(std::string str) : Component(str) {}
    void add(Component* p) {
        std::cout << "Leaf can not add component!" << std::endl;
    }
    void remove(Component* p) {
        std::cout << "Leaf can not remove component!" << std::endl;
    }
    void display() {
        std::cout << strName_ << std::endl;
    }
};

class Composite : public Component
{
private:
    std::vector<std::shared_ptr<Component>> vec_;
public:
    Composite(std::string str) : Component(str) {}
    ~Composite() {
        if (!vec_.empty()) {
            vec_.clear();
        }
    }
    void add(Component* p) {
        auto it = find_if(vec_.begin(), vec_.end(),
            [p](std::shared_ptr<Component> ptr) { return p == ptr.get();});
        if (it == vec_.end()) {
            vec_.push_back(std::shared_ptr<Component>(p));
        }
    }
    void remove(Component* p) {
        auto it = find_if(vec_.begin(), vec_.end(),
            [p](std::shared_ptr<Component> ptr) { return p == ptr.get();});
        if (it == vec_.end()) {
            return ;
        }
        vec_.erase(it);
    }
    void display() {
        for (auto it = vec_.begin(); it != vec_.end(); ++it) {
            (*it)->display();
        }
    }
};
