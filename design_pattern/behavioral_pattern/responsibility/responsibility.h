#pragma once

#include <iostream>

/*
    案例：
    对于不同金额的票据，公司不同级别的领导处理情况如下：
    金额0~10万：组长可处理
    金额10~30万：主管处理
    金额30~60万：经理处理
    金额超过60万：老板处理
 */


// 请求：票据
class Bill
{
public:
    Bill(){}
    Bill(int iId, std::string iName, double iAccount)
        : id_(iId), name_(iName), account_(iAccount)
    {}
    double getAccount()
    {
        return this->account_;
    }
    void print()
    {
        printf("\nID:\t%d\n", id_);
        printf("Name:\t%s\n", name_.c_str());
        printf("Account:\t%f\n", account_);
    }
private:
    int id_;
    std::string name_;
    double account_;
};

// 抽象处理者
class Approver
{
public:
    Approver(){}
    Approver(std::string iName) : name_(iName) {}
    // add superior
    void addSuperior(Approver* superior)
    {
        superior_ = superior;
    }
    // handle request
    virtual void handleRequest(Bill* ) = 0;
    std::string getName() { return name_; }
    void setName(std::string name) { name_ = name; }
protected:
    Approver* superior_;
private:
    std::string name_;
};

// 具体处理者：组长
class GroupLeader : public Approver
{
public:
    GroupLeader(){}
    GroupLeader(std::string name) { setName(name); }
    // 处理请求
    void handleRequest(Bill* bill)
    {
        if (bill->getAccount() < 10)
        {
            printf("组长 %s 处理了该票据，票据信息：",this->getName().c_str());
            bill->print();
        }
        else 
        {
            printf("组长无权处理，转交上级……\n");
            this->superior_->handleRequest(bill);
        }
    }
};


// 具体处理者：主管
class Head :public Approver
{
public:
	Head(){}
	Head(std::string iName){
		setName(iName);
	}
	// 处理请求
	void handleRequest(Bill *bill){
		if (bill->getAccount() >= 10 && bill->getAccount()<30){
			printf("主管 %s 处理了该票据，票据信息：", this->getName().c_str());
			bill->print();
		}
		else{
			printf("主管无权处理，转交上级……\n");
			this->superior_->handleRequest(bill);
		}
	}
};


// 具体处理者：经理
class Manager :public Approver
{
public:
	Manager(){}
	Manager(std::string iName){
		setName(iName);
	}
	// 处理请求
	void handleRequest(Bill *bill){
		if (bill->getAccount() >= 30 && bill->getAccount()<60){
			printf("经理 %s 处理了该票据，票据信息：", this->getName().c_str());
			bill->print();
		}
		else{
			printf("经理无权处理，转交上级……\n");
			this->superior_->handleRequest(bill);
		}
	}
};

// 具体处理者：老板
class Boss :public Approver
{
public:
	Boss(){}
	Boss(std::string iName){
		setName(iName);
	}
	// 处理请求
	void handleRequest(Bill *bill){
		printf("老板 %s 处理了该票据，票据信息：", this->getName().c_str());
		bill->print();
	}
};

