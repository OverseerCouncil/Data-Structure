#include<iostream>

using namespace std;

char firstSingle(char* str)
{
	const int size = 26;
	int hash[26] = { 0 };
	char* hashkey = str;
	while (*hashkey != '\0')
	{
		hash[*(hashkey++) - 97]++;
	}
	hashkey = str;
	while (*hashkey != '\0')
	{
		if (hash[*hashkey - 97] == 1)
		{
			return *hashkey;
		}
		hashkey++;
	}
	return '\0';
}

int main()
{
	char s[1000];
	cout << "输入字符串" << endl;
	cin >> s;
	cout << firstSingle(s) << endl;
}