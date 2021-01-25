#include "string.h"
#include <assert.h>


int main()
{
    my_string::String s1;

    // 拷贝构造
    my_string::String s2("hello");
    s2.print();
    std::cout << "s2.size(): " << s2.size() << std::endl;
    std::cout << "s2.c_str(): " << s2.c_str() << std::endl;

    // 赋值构造
    my_string::String s3;
    s3 = "hello world";
    std::cout << "s3: " << std::endl;

    my_string::String s4;
    s4 = s3;
    std::cout << "s4: " << s4 << std::endl;

    assert(s4 == s3);
    assert(s4 != s2);
    assert(s4 >= s2);
    assert(s4 > s2);
    assert(s2 < s4);
    assert(s2 <= s4);

    my_string::String t1 ;
    t1 = "beij";
    t1 += "shangh";
    std::cout << "t1: " << t1 << std::endl;
     
    my_string::String t2;
    t2 = "shenzh";
    t1 += t2 ;
    std::cout << "t1: " << t1 << std::endl;

    t1[0]= 'A';
    std::cout << "t1: " << t1 << std::endl;

    my_string::String u1 ,u2;
    u1 = s2;
    u2 = "wow";
   
    u1 = u2 + " my god";
    std::cout << "u1: " << u1 << std::endl;

    u1 = t2 + u2 ;
    std::cout << "u1: " << u1 << std::endl;
 
    std::cout << "before:" ;
    std::cout << s4 << "  " << u2 << std::endl;
    
    std::cout << "swap"<< std::endl;
    u2.swap(s4);
    std::cout << "after:"; 
    std::cout << s4 << "  " << u2 << std::endl;

    return 0;
}