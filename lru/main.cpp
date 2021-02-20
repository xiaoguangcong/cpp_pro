#include "lru.h"

int main()
{
    int value;
    LRUCache<std::string, int> cache(5);

    cache.put("aaa", 1);
    cache.put("bbb", 2);
    cache.put("ccc", 3);
    cache.put("ddd", 4);
    cache.put("eee", 5);
    
    cache.show(show_func);

    cache.get("ccc", value);

    cache.show(show_func);

    cache.put("fff", 6);

    cache.show(show_func);

    return 0;

}
