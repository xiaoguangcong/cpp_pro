#pragma once
#include <cstdio>
#include <iostream>
#include <vector>
#include <mutex>

/*
    很多网络设备都是支持共享的，如交换机（switch）、集线器（hub）等。
    多台中断计算机可以连接同一台网络设备，并通过网络设备进行数据转发。
    将使用享元模式来模拟共享网络设备的实例。
 */

// 抽象享元
class NetDevice
{
public:
    NetDevice(){}
    virtual std::string getName() = 0;

    void print()
    {
        std::printf("NetDevice :%s\n", getName().c_str());
    }
};

// 具体享元类：集线器
class Hub : public NetDevice
{
public:
    Hub(){}
    std::string getName()
    {
        return "集线器";
    }
};

// 具体享元类：交换机
class Switch : public NetDevice
{
public:
    Switch(){}
    std::string getName()
    {
        return "交换机";
    }
};

// 享元工厂类，单例模式
class NetDeviceFactory
{
public:
    NetDevice* getNetDevice(char ch)
    {
        if (ch == 'S')
        {
            return devicePool[1];
        }
        else if (ch == 'H')
        {
            return devicePool[0];
        }
        return NULL;
    }

    static NetDeviceFactory* getFactory()
    {
        if (instance == NULL)
        {
            m_mutex.lock();
            if (instance == NULL)
            {
                instance = new NetDeviceFactory();
            }
            m_mutex.unlock();
        }
        return instance;
    }
private:
    NetDeviceFactory()
    {
        Hub* hub = new Hub();
        Switch* switcher = new Switch();
        devicePool.push_back(hub);
        devicePool.push_back(switcher);
    }
    static NetDeviceFactory* instance;
    static std::mutex m_mutex;

    // 共享池
    std::vector<NetDevice*> devicePool;
};

NetDeviceFactory* NetDeviceFactory::instance = NULL;
std::mutex NetDeviceFactory::m_mutex;