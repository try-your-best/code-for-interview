#include <iostream>
#include <climits>
using namespace std;

enum Status {valid = 0, invalid};
Status g_status = valid;

int StrToInt(const char *str);
long long  StrToIntCore(const char *str, bool mimus);

int StrToInt(const char *str)//注意函数签名，const char *！
{
	g_status = invalid;//先将状态设置为无效，方便函数随时退出
	long long num = 0;
	if(str == NULL || *str == '\0')//检查输入是否有效
		return (int)num;
	bool minus = false;
	if(*str == '+')
	{
		str++;
	}
	else if(*str == '-')
	{
		minus = true;
		str++;
	}
	num = StrToIntCore(str, minus);
	return (int)num;
}

long long StrToIntCore(const char *digit, bool minus)
{
	long long num = 0; //注意 num 有效范围必须比int大，类型为long long
	while(*digit != '\0')
	{
		if( *digit >= '0' && *digit <= '9')//检查输入符号的是否有效
		{
			int flag = minus ? -1 : 1;
			num = num * 10 + flag * (*digit - '0');
			if((minus && num < INT_MIN) || (!minus && num > INT_MAX))//检查函数的范围！
			{
				num = 0;
				break;
			}
		}
		else
		{
			num = 0;
			break;
		}
		digit++;
	}
	if(*digit == '\0')
	{
		g_status = valid;
	}
	return num;
}

void Test()
{
	//char str[] = "-2147483648";
	char str[] = "2147483648";
	//cout << INT_MIN << endl;
	cout << StrToInt(str) << endl;
	if(g_status == invalid)
	{
		cout << "invalid" << endl;
		cout << g_status << endl;
	}
}

int main() {
	Test();
	return 0;
}
