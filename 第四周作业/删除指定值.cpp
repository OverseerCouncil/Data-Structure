#include<iostream>

using namespace std;

char str[1000];
char ch;

void Del(char* s, char ch)
{
	int fast, slow;
	for (fast = slow = 0; str[fast] != '\0'; fast++)
	{
		if (str[fast] != ch)
		{
			str[slow] = str[fast];
			slow++;
		}
	}
	str[slow] = '\0';
	for (int x = slow + 1; x < fast; x++)
	{
		str[x] = NULL;
	}
}

int main()
{
	cout << "请输入字符串" << endl;
	cin >> str;
	cout << "请输入要删除的字符" << endl;
	cin >> ch;
	Del(str, ch);
	cout << str;
}