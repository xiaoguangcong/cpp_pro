#ifndef __CODEVERSION_H__
#define __CODEVERSION_H__

#include <iostream>
#include "Memento.h"

// 原生器：CodeVersion
class CodeVersion
{
public:
    CodeVersion() : version_(0), date_("1900-01-01"), label_("none") {}
	CodeVersion(int version, std::string date, std::string label)
        : version_(version), date_(date), label_(label)
    {}
    // 保存代码
    Memento* save()
    {
        return new Memento(this->version_, this->date_, this->label_);
    }
    // 回退版本
    void restore(Memento* mememto)
    {
        setVersion(mememto->getVersion());
        setDate(mememto->getDate());
        setLabel(mememto->getLabel());
    }
    void setVersion(int version) { version_ = version; }
    int getVersion() { return version_; }
    void setLabel(std::string label) { label_ = label; }
    std::string getLabel() { return label_; }
    void setDate(std::string date) { date_ = date; }
    std::string getDate() { return date_; }
private:
    // 代码版本
	int version_;
	// 代码提交日期
	std::string date_;
	// 代码标签
	std::string label_;
};

#endif