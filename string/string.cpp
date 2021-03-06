#include<iostream>
#include <string.h>

using namespace std;

class String
{
public:
    String():m_data(new char[1])
    {
        m_data[0] = '\0';//注意，不要写成 m_data = '\0';
    }
    String(const char* str):m_data(new char[strlen(str)+1]) // 如果输入NULL，由strlen解决
    {
        strcpy(m_data, str);
    }
	String(const String& rhs):m_data(new char[rhs.size()+1])//使用 rhs.size()获取长度
    {
        strcpy(m_data, rhs.c_str());
    }
    //Traditional
//    String& operator = (const String& rhs)
//    {
//        String tmp(rhs);
//        swap(tmp);
//        return *this;
//    }
    String& operator=(String rhs) // yes, pass-by-value
    {
      swap(rhs);
      return *this;
    }
    ~String()
    {
        delete[] m_data;
    }
    const char* c_str() const //使用const 修饰函数
    {
        return m_data;
    }
    void swap(String& rhs)//注意，不是const String& rhs, 否则m_data 变为const，无法swap;
    {
        std::swap(m_data, rhs.m_data); //注意，不是rhs.c_str()
    }
    size_t size() const
    {
        return strlen(m_data);
    }
private:
    char* m_data;
};

/*
1、只在构造函数里调用 new char[]，只在析构函数里调用 delete[]。
2、赋值操作符采用了《C++编程规范》推荐的现代写法。
3、每个函数都只有一两行代码，没有条件判断。
4、析构函数不必检查 data_ 是否为 NULL。
5、构造函数 String(const char* str) 没有检查 str 的合法性，这是一个永无止境的争论话题。
这里在初始化列表里就用到了 str，因此在函数体内用 assert() 是无意义的。
*/
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
    String str1(NULL);
    cout << str1.c_str() << endl;
}

int main()
{
    Test();
    return 0;
}
