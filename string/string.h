#include <iostream>
#include <string.h>

namespace my_string
{
class String
{
    friend std::ostream& operator<<(std::ostream&, String& str);
    friend std::istream& operator>>(std::istream&, String& str);

    friend String operator+(const String &str1, const String &str2); 
    friend String operator+(const String &str, const char *c); 
    friend String operator+(const char *c, const String &str);

    friend bool operator>(const String &s1, const String &s2);
    friend bool operator>=(const String &s1, const String &s2);
    friend bool operator<(const String &s1, const String &s2);
    friend bool operator<=(const String &s1, const String &s2);
    friend bool operator==(const String &s1, const String &s2);
    friend bool operator!=(const String &s1, const String &s2);

public:
    String(const char* ptr = nullptr);
    String(const String& str);
    ~String();

    String& operator=(const String& str);
    String& operator=(const char* c);
    String& operator+=(const String& str);
    String& operator+=(const char* c);
    char &operator[](size_t n);
    const char operator[](size_t n) const;
    size_t size() const;
    const char* c_str();

    void swap(String& str);
    void print() const;

private:
    char* data;
    size_t length;
};

};