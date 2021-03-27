#ifndef __MEMENTO_H__
#define __MEMENTO_H__

#include <cstdio>
#include <iostream>

class Memento
{
public:
    Memento(){}
    Memento(int version, std::string date, std::string label)
        : version_(version), date_(date), label_(label)
    {}
    void setVersion(int version) { version_ = version; }
    int getVersion() { return version_; }
    void setLabel(std::string label) { label_ = label; }
    std::string getLabel() { return label_; }
    void setDate(std::string date) { date_ = date; }
    std::string getDate() { return date_; }

private:
    int version_;
    std::string date_;
    std::string label_;
};

#endif