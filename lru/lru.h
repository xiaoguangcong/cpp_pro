#include <iostream>
#include <list>
#include <string>
#include <unordered_map>

/***
 * LRU，Least Recently Used，最近最久未使用。常用于页面置换算法。是为虚拟页式存储管理服务的。
 * 对于在内存中又不用的数据块，称为LRU，操作系统会根据哪些数据属于LRU而将其移出内存。
***/

template<class KeyType, class ValueType>
class LRUCache
{
public:
    LRUCache(int capacity) : m_capacity(capacity) {}

    int get(KeyType key, ValueType &value)
    {
        if(m_map.count(key) <= 0) {
            return -1;
        }

        Iter iter = m_map[key];
        value = iter->second;

        m_list.splice(m_list.begin(), m_list, iter);

        return 0;
    }

    void put(KeyType key, ValueType value)
    {
        if(m_map.count(key) >= 1)
        {
            Iter iter = m_map[key];
            iter->second = value;
            m_list.splice(m_list.begin(), m_list, iter);
        } 
        else 
        {
            Node node(key, value);
            if(m_list.size() == m_capacity)
            {
                m_map.erase(m_list.back().first);
                m_list.pop_back();
            }

            m_list.push_front(node);
            m_map[key] = m_list.begin();
        }
    }

    void show(void(*p)(ValueType *))
    {
        typename std::list<Node>::iterator it;
        for(it = m_list.begin(); it != m_list.end(); ++it)
        {
            p(&it->second);
        }
    }

private:
    typedef std::pair<KeyType, ValueType> Node;
    typedef typename std::list<Node>::iterator Iter;
    std::list<Node> m_list;
    std::unordered_map<KeyType, Iter> m_map;
    int m_capacity;
};

void show_func(int *a)
{
    printf("%d\n", *a);
}