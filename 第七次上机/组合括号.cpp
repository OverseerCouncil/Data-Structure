#include<iostream>
#include<vector>
#include<string>

using namespace std;

void generate(int leftNum, int rightNum, string s, vector<string>& res)
{
	if (leftNum == 0 && rightNum == 0)
	{
		res.push_back(s);
	}
	if (leftNum > 0)
	{
		generate(leftNum - 1, rightNum, s + '(', res);
	}
	if (rightNum > 0 && leftNum < rightNum)
	{
		generate(leftNum, rightNum - 1, s + ')', res);
	}
}

int main()
{
	int n;
	vector<string> answer;
	cout << "请输入n大小";
	cin >> n;
	generate(n, n, "", answer);
	for (unsigned int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << ",";
	}
}