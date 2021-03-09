#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int minDistance(string a, string b)
{
	int Alen = a.length();
	int Blen = b.length();
	vector<vector<int>>DisMap;
	for (int i = 0; i < Alen + 1; i++)
	{
		vector<int>in;
		for (int j = 0; j < Blen + 1; j++)
		{
			int input;
			if ((i == 0) | (j == 0))
			{
				input = i > j ? i : j;
			}
			else
			{
				input = 0;
			}
			in.push_back(input);
		}
		DisMap.push_back(in);
		in.clear();
	}

	for (int i = 1; i < Alen + 1; i++)
	{
		for (int j = 1; j < Blen + 1; j++)
		{
			int up = DisMap[i - 1][j] + 1;
			int left = DisMap[i][j - 1] + 1;
			int upleft = DisMap[i - 1][j - 1];
			if (a[i - 1] != b[j - 1])
			{
				upleft += 1;
			}
			DisMap[i][j] = min(up, min(left, upleft));
		}
	}
	return DisMap[Alen][Blen];
}

int main()
{
	string A, B;
	cin >> A;
	cin >> B;
	cout << minDistance(A, B);
}