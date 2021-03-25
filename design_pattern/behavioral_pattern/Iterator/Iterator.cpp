#include "Iterator.h"
#include <cstdio>


Iterator* Television::createIterator()
{
    RemoteControl *it = new RemoteControl();
    it->setTV(this);
    return (Iterator*)it;
}

int Television::getTotalChannelNum()
{
    return channelList_.size();
}

void Television::play(int i)
{
    printf("现在播放：%s……\n", channelList_[i].c_str());
}