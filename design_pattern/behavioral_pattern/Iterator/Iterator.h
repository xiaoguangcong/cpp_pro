#pragma once

#include <iostream>
#include <vector>

/*
    电视机遥控器是迭代器的一个现实应用，通过它可以实现对电视频道集合的遍历操作，
    电视机可以看成一个存储频道的聚合对象。采用迭代器模式来模拟遥控器操作电视频道的过程。
 */


// 前向声明，因为两个类互相引用
class Iterator;
class RemoteControl;


// 抽象迭代器
class Iterator
{
public:
    Iterator(){}
    // 声明抽象遍历方法
    virtual void first() = 0;
    virtual void last() = 0;
    virtual void next() = 0;
    virtual void previous() = 0;
    virtual bool hasNext() = 0;
    virtual bool hasPrevious() = 0;
    virtual void currentChannel() = 0;
};

// 抽象聚合类
class Aggregate
{
public:
    Aggregate(){}
    virtual Iterator* createIterator() = 0;
};

// 具体聚合类 Television
class Television : public Aggregate
{
public:
    Television(){}
    Television(std::vector<std::string> channelList) : channelList_(channelList) {}
    // 实现创建迭代器
    Iterator* createIterator();
    // 获取总的频道数
    int getTotalChannelNum();
    void play(int i);
private:
    std::vector<std::string> channelList_;
};

// 遥控器：具体迭代器
class RemoteControl : Iterator
{
public:
    RemoteControl(){}
    void setTV(Television* tv)
    {
        this->tv_ = tv;
        cursor_ = -1;
        totalNum_ = tv->getTotalChannelNum();
    }
    // 实现各个遍历方法
	void first(){
		cursor_ = 0;
	}
	void last(){
		cursor_ = totalNum_ - 1;
	}
	void next(){
		cursor_++;
	}
	void previous(){
		cursor_--;
	}
	bool hasNext(){
		return !(cursor_ == totalNum_);
	}
	bool hasPrevious(){
		return !(cursor_ == -1);
	}
	void currentChannel(){
		tv_->play(cursor_);
	}

private:
    int cursor_;
    int totalNum_;
    Television* tv_;
};