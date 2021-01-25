#include "string.h"

namespace my_string 
{

String::String(const char* ptr)
{
    if (ptr == nullptr) {
        data = '\0';
        length = 0;
    } else {
        length = strlen(ptr);
        data = new char[length+1];
        strcpy(data, ptr);
    }
}

String::String(const String& str)
{
    if (str.data == nullptr) {
        data = '\0';
    } else {
        length = str.length;
        data = new char[length+1];
        strcpy(data, str.data);
    }
}

// 赋值时必须判断左右操作数是否相同；否则delete[]将会把“自己”删除
String& String::operator=(const String& str)
{
    if (this != &str) {
        length = strlen(str.data);
        delete[] data;
        data = new char[length+1];
        strcpy(data, str.data);
    }
    return *this;
}

String& String::operator=(const char* c)
{
    if (data != c) {
        delete[] data;
        data = new char[strlen(c)+1];
        strcpy(data, c);
    }
    return *this;
}

// 复合赋值的步骤：
// 产生一个临时变量，将左右操作数复制于其中；
// 删除原来的成员， 将临时变量copy至成员中
String& String::operator+=(const String& str)
{
     length += str.length;
     char* tmp = new char[length+1];
     strcpy(tmp, data);
     strcat(tmp, str.data);
     delete[] data;
     data = tmp;
     return *this;
}

String& String::operator+=(const char* c)
{
    length += strlen(c);
    char *tmp = new char[length+1];
    strcpy(tmp, data);
    strcat(tmp, c);

    delete[] data;
    data = tmp;
    return *this;
}

char& String::operator[](size_t n)
{
    return data[n];
}


const char String::operator[](size_t n) const
{
    return data[n];
}

size_t String::size() const
{
    return length;
}

std::ostream& operator<<(std::ostream& os, String& str)
{
    os << str.data;
    return os;
}

std::istream& operator>>(std::istream& is, String& str)
{
    char tmp[1024];
    if (is >> tmp)//注意要检查错误
       str.data = tmp;
    return is;
}

const char* String::c_str()
{
    return data;
}

String::~String()
{
    if (data != nullptr) {
        delete []data;
        data = nullptr;
        length = 0;
    }
}

String operator+(const String &str1, const String &str2)
{
    String str(str1);
    str += str2;
    return str;
}

String operator+(const char *c, const String &str)
{
    String str1(str);
    str1 += c;
    return str1;
}

String operator+(const String &str, const char *c)
{
    String str1(str);
    str1 += c;
    return str1;
}

bool operator>(const String& str1, const String& str2)
{
    return ::strcmp(str1.data, str2.data) > 0;
}

bool operator>=(const String& str1, const String& str2)
{
    return !(str1 < str2);
}

bool operator<(const String& str1, const String& str2)
{
    return !((str1 > str2) || (str1 == str2));
}

bool operator<=(const String& str1, const String& str2)
{
    return !(str1 > str2);
}

bool operator==(const String& str1, const String& str2)
{
    return ::strcmp(str1.data, str2.data) == 0;
}

bool operator!=(const String& str1, const String& str2)
{
    return !(str1 == str2);
}

void String::swap(String& str)
{
    std::swap(data, str.data);
}

void String::print() const
{
    std::cout << data << std::endl;
}

};