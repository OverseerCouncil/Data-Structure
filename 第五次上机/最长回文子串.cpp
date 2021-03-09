#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int LongestPalindrome(string s)
{
	int MaxLen = -1;
	int Ctr;
	int Rad = 0;
	string SupStr="$#";
	for (unsigned int i = 0; i < s.size(); i++)
	{
		SupStr += s[i];
		SupStr += '#';
	}
	vector<int>Length(SupStr.size(), 0);
	for (int j = 1; j < SupStr.size(); j++)
	{
		if (j < Rad)
		{
			Length[j] = min(Length[2 * Ctr - j], Rad - j);
		}
		else
		{
			Length[j] = 1;
		}
		while (SupStr[j - Length[j]] == SupStr[j + Length[j]])
		{
			Length[j]++;
		}
		if (Rad < j + Length[j])
		{
			Ctr = j;
			Rad = j + Length[j];
		}
		MaxLen = max(MaxLen, Length[j] - 1);
	}
	return MaxLen;
}

int main()
{
	vector<string>Mylist;
	unsigned int num;
	string temp;
	cin >> num;
	for (unsigned int i = 0; i < num; i++)
	{
		cin >> temp;
		Mylist.push_back(temp);
	}
	for (unsigned int j = 0; j < num; j++)
	{
		cout << LongestPalindrome(Mylist[j]) << endl;
	}
	system("pasue");
}