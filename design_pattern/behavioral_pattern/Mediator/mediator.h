#include "common.h"

class Colleague;

// 抽象中介者
class Mediator
{
public:
    Mediator(){}
    // 声明抽象方法
    virtual void operation(Colleague*) = 0;
    // 声明注册方法
    virtual void registerMethod(Colleague*) = 0;
};

// 抽象同事类
class Colleague
{
public:
    Colleague(){}
    void setMediator(Mediator* mediator)
    {
        this->mediator_ = mediator;
    }
    void setPersonType(PERSON_TYPE personType)
    {
        this->personType_ = personType;
    }
    PERSON_TYPE getPersonType()
    {
        return personType_;
    }
    Mediator* getMediator()
    {
        return mediator_;
    }
    virtual void ask() = 0;
    virtual void answer() = 0;
private:
    PERSON_TYPE personType_;
    Mediator* mediator_;
};

// 具体同事类：房东
class Landlord : public Colleague
{
public:
    Landlord(){}
    Landlord(std::string name, int price, std::string address, std::string phoneNumber)
        : name_(name), price_(price), address_(address), phoneNumber_(phoneNumber)
    {
        setPersonType(LANDLORD);
    }
    
    void answer()
    {
	    printf("房东姓名：%s, 房租：%d, 地址：%s, 联系电话：%s\n",
		    name_.c_str(), price_, address_.c_str(), phoneNumber_.c_str());
    }

    void ask()
    {
        printf("房东%s查看租客信息：\n", name_.c_str());
	    (this->getMediator())->operation(this);
    }

private:
    std::string name_;
    int price_;
    std::string address_;
    std::string phoneNumber_;
};

class Tenant : public Colleague
{
public:
    Tenant(){}
    Tenant(std::string name) : name_(name) 
    {
        setPersonType(TENANT);
    }
    void ask()
    {
	    printf("租客%s询问房东信息\n", name_.c_str()); 
	    (this->getMediator())->operation(this);
    }
    void answer()
    {
	    printf("租客姓名：%s\n", name_.c_str());
    }

private:
    std::string name_;
};

// 具体中介者
class Agency:public Mediator
{
public:
	Agency(){}
	void registerMethod(Colleague* person){
		switch (person->getPersonType()){
		case LANDLORD:
			landlordList.push_back((Landlord*)person);
			break;
		case TENANT:
			tenantList.push_back((Tenant*)person);
			break;
		default:
			printf("wrong person\n");
		}
	}
	void operation(Colleague* person){
		switch (person->getPersonType()){
		case LANDLORD:
			for (int i = 0; i < tenantList.size(); i++){
				tenantList[i]->answer();
			}
			break;
		case TENANT:
			for (int i = 0; i < landlordList.size(); i++){
				landlordList[i]->answer();
			}
			break;
		default:
			break;
		}
	}
private:
	std::vector<Landlord*>landlordList;
	std::vector<Tenant*>tenantList;
};