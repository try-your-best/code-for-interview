#include<iostream>
#include <assert.h>     /* assert */
using namespace std;

//char* strcpy(char* dest, const char* source)
//{
//    if(dest == NULL || source == NULL)
//    {
//        return NULL;
//    }
//    while(*source != '\0')
//    {
//        *dest++ = *source++;
//    }
//    *dest = '\0';
//    return dest;
//}

char* strcpy(char* dest, const char* source)
{
    assert(dest != NULL && source != NULL);
    while(*source != '\0')
    {
        *dest++ = *source++;
    }
    *dest = '\0';
    return dest;
}

void Test()
{
    char* source = "12345678910";
    char dest[20];
    strcpy(NULL, source);
    cout << dest << endl;
}

int main()
{
    Test();
    return 0;
}
