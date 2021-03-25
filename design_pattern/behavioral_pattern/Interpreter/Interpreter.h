#pragma once

#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>

/*
    实例：
    设计一个简单的解释器，使得系统可以解释0和1的或运算和与运算
    （不考虑或运算和与运算的优先级，即从左往右依次运算）。
 */

// 抽象表达式类
class AbstractNode
{
public:
    AbstractNode(){}
    // 声明抽象接口
    virtual char interpret() = 0;
};


// 终结符表达式-值：ValueNode
class ValueNode : public AbstractNode
{
public:
    ValueNode(){}
    ValueNode(int value) : value_(value) {}

    // 实现解释操作
    char interpret()
    {
        return value_;
    }
private:
    int value_;
};


// 终结符表达式-运算符：OperationNode
class OperatorNode : public AbstractNode
{
public:
    OperatorNode(){}
    OperatorNode(std::string op) : op_(op) {}
    // 实现解释操作
    char interpret()
    {
        if (op_ == "and")
        {
            return '&';
        }
        else if (op_ == "or")
        {
            return '|';
        }
        return 0;
    }
private:
    std::string op_;
};

// 非终结符表达式：SentenceNode
class SentenceNode : public AbstractNode
{
public:
    SentenceNode(){}
    SentenceNode(AbstractNode *l, AbstractNode *r, AbstractNode *o)
        : leftNode_(l)
        , rightNode_(r)
        , operatorNode_(o)
    {}
    char interpret()
    {
        if (operatorNode_->interpret() == '&')
        {
            return leftNode_->interpret() & rightNode_->interpret();
        }
        else if (operatorNode_->interpret() == '|')
        {
            return leftNode_->interpret() | rightNode_->interpret();
        }
        return 0;
    }
private:
    AbstractNode *leftNode_;
    AbstractNode *rightNode_;
    AbstractNode *operatorNode_;
};

// 处理者: 将处理输入的表达式，并解释出表达式最终的结果。
class Handler
{
public:
    Handler(){}
    Handler(std::string input) : input_(input) {}
    void setInput(std::string iInput){
		this->input_ = iInput;
	}
    void handle()
    {
        AbstractNode *left = NULL;
        AbstractNode *right = NULL;
        AbstractNode *op = NULL;
        AbstractNode *sentence = NULL;
        std::string iInput = this->input_;
        std::vector<std::string> inputList;
        char *inputCh = const_cast<char*>(iInput.c_str());
        char *token = strtok(inputCh, " ");
        while (token != NULL)
        {
            inputList.push_back(token);
            token = strtok(NULL, " ");
        }
        for (int i = 0; i < inputList.size() - 2; i += 2)
        {
            left = new ValueNode(*(inputList[i].c_str()));
            op = new OperatorNode(inputList[i+1]);
            right = new ValueNode(*(inputList[i+2].c_str()));
            sentence = new SentenceNode(left, right, op);
            inputList[i+2] = std::string(1, sentence->interpret());
        }
        std::string tmpRes = inputList[inputList.size() - 1];
        if (tmpRes == "1")
        {
            result_ = 1;
        }
        else if (tmpRes == "0")
        {
            result_ = 0;
        }
        else 
        {
            result_ = -1;
        }
        this->output();
    }

    void output()
    {
        printf("%s = %d\n", input_.c_str(), result_);
    }

private:
    std::string input_;
    char result_;
};
