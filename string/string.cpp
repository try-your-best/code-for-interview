#include<iostream>
#include <string.h>

using namespace std;

//void Swap(char*& str1, char*& str2)
//{
//    if(str1 == str2)
//        return;
//    char* tmp = str1;
//    str1 = str2;
//    str2 = tmp;
//}

class String
{
public:
    String():m_data(new char[1])
    {
        m_data[0] = '\0';
    }
    String(const char* str):m_data(new char[strlen(str)+1])
    {
        strcpy(m_data, str);
    }
    String(const String& rhs):m_data(new char[strlen(rhs.c_str())+1])//细心，把1放到[]内。
    {
        strcpy(m_data, rhs.c_str());
    }
    String& operator = (const String& rhs)
    {
        String tmp(rhs);
        swap(tmp);
        return *this;
    }
    ~String()
    {
        delete[] m_data;
    }
    const char* c_str() const
    {
        return m_data;
    }
    void swap(String& rhs)//注意，不是const String& rhs
    {
        std::swap(m_data, rhs.m_data); //注意，不是rhs.c_str()
//        Swap(m_data, rhs.m_data);
    }
    size_t size() const
    {
        return strlen(m_data);
    }
private:
    char* m_data;
};

void Test()
{
    String str1("hello");
    String str2("world");
    str1 = str2;
    cout << str1.c_str() << endl;
    //const char* str3 =  str1.c_str();
    //cout << str3 << endl;
}

void Test2()
{
    String str1("hello");
    cout << str1.c_str() << endl;
}

int main()
{
    Test();
    return 0;
}
