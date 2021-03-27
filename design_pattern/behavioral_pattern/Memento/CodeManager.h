#ifndef __CODEMANAGER_H__
#define __CODEMANAGER_H__

#include "Memento.h"
#include <vector>

class CodeManager
{
public:
    CodeManager(){}
    void commit(Memento* m)
    {
        printf("提交: 版本-%d，日期-%s，标签-%s\n", m->getVersion(), m->getDate().c_str(), m->getLabel().c_str());
        mememtoList_.push_back(m);
    }
    // 切换到指定的版本，即回退到指定版本
    Memento* switchToPointedVersion(int index)
    {
        mememtoList_.erase(mememtoList_.begin() + mememtoList_.size() - index, mememtoList_.end());
        return mememtoList_[mememtoList_.size() - 1];
    }
    // 打印历史版本
    void codeLog()
    {
        for (int i = 0; i < mememtoList_.size(); ++i)
        {
            printf("[%d]：版本-%d, 日期-%s, 标签-%s\n", i, mememtoList_[i]->getVersion(),
                mememtoList_[i]->getDate().c_str(), mememtoList_[i]->getLabel().c_str());
        }
    }
private:
    std::vector<Memento*> mememtoList_;
};

#endif