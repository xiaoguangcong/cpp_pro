#pragma once

#include <cstdio>
#include <iostream>
#include <pthread.h>

/*
    实例：
    房间中的开关（Button）就是命令模式的一个实现，
    本例使用命令模式来模拟开关功能，可控制的对象包括电灯（Lamp）和风扇（Fan）。
    用户每次触摸（touch）开关，都可以打开或者关闭电灯或者电扇。
 */

// 接收者：电灯类
class Lamp
{
public:
    Lamp() : lampState_(false) {}
    void on()
    {
        lampState_ = true;
        printf("Lamp is on\n");
    }
    void off()
    {
        lampState_ = false;
        printf("Lamp is off\n");
    }
    bool getLampState()
    {
        return lampState_;
    }
private:
    bool lampState_;
};

// 接收者：风扇类
class Fan
{
public:
    Fan() : fanState_(false) {}
    void on()
    {
        fanState_ = true;
        printf("Fan is on\n");
    }
    void off()
    {
        fanState_ = false;
        printf("Fan is off\n");
    }
    bool getFanState()
    {
        return fanState_;
    }
private:
    bool fanState_;
};

// 抽象命令类
class Command
{
public:
    Command(){}
    // 声明一个抽象接口，发送命令
    virtual void execute() = 0;
private:
    Command* command_;
};

// 具体命令类 LampCommand
class LampCommand : public Command
{
public:
    LampCommand()
    {
        printf("开关控制电灯\n");
        lamp_ = new Lamp();
    }
    void execute()
    {
        if (lamp_->getLampState())
        {
            lamp_->off();
        }
        else {
            lamp_->on();  
        }
    }
private:
    Lamp* lamp_;
};

// 具体命令类 FanCommand
class FanCommand : public Command
{
public:
    FanCommand()
    {
        printf("开关控制风扇\n");
        fan_ = new Fan();
    }
    void execute()
    {
        if (fan_->getFanState())
        {
            fan_->off();
        }
        else {
            fan_->on();
        }
    }
private:
    Fan* fan_;
};

// 调用者Button
class Button
{
public:
    Button(){}
    // 注入具体命令类对象
    void setCommand(Command* command) {
        command_ = command;
    }
    // 发送命令：触摸按钮
    void touch()
    {
        printf("触摸开关：");
        command_->execute();
    }
private:
    Command* command_;
};