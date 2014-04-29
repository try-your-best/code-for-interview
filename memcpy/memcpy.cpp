#include <iostream>
#include <assert.h>
using namespace std;

//注意函数的签名！！ 如果两个地址段有重叠的地方，则后果是不确定的！
//void * memcpy ( void * destination, const void * source, size_t num );
void *memcpy(void *dest, const void *source, size_t count)
{
	assert(dest != NULL && source != NULL);
	void *result = dest;
	while(count--) //注意，是count--，不是--count;
	{
		*(char*) dest = *(char*)source;//每次拷贝一个字节的值
		dest = (char*)dest + 1;
		source = (char*)source + 1;
	}
	return result;
}

void Test()
{
	int num1 = 123456;
	int num2 =0;
	void *result = memcpy(&num2, &num1, sizeof(num1));
	cout << *(int *)result << endl;
}


int main() {
	Test();
	return 0;
}
