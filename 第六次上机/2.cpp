#include<iostream>
#include<vector>
#include<stack>

using namespace std;


int main()
{
	vector<int> nums;
	stack<int> s;
	int Input;
	cout << "以空格为分割，回车为结束" << endl;
	while (cin >> Input)
	{
		nums.push_back(Input);
		if (cin.get() == '\n')
		{
			break;
		}
	}
	vector<int> res(nums.size(), 0);
	for (int j = 0; j < nums.size(); j++)
	{
		while (!s.empty() && nums[s.top()] <= nums[j])
		{
			res[s.top()] = j - s.top();
			s.pop();
		}
		s.push(j);
	}
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
}

