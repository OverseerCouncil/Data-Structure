#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> BIN;
	vector<int> OCT;
	unsigned int x;
	unsigned int opr;
	unsigned int cur;
	cin >> x;
	if (!x)
	{
		cout << "0";
		return 0;
	}
	while (x != 0)
	{
		opr = x % 2;
		x = x / 2;
		BIN.push_back(opr);
	}
	while (BIN.size() % 3)
	{
		BIN.push_back(0);
	}
	for (unsigned int i = 0; i < BIN.size() / 3; i = i++ )
	{
		cur = BIN[3 * i] + BIN[3 * i + 1] * 2 + BIN[3 * i + 2] * 4;
		OCT.push_back(cur);
	}
	reverse(OCT.begin(), OCT.end());
	for (unsigned int j = 0; j < OCT.size(); j++)
	{
		cout << OCT[j];
	}
}