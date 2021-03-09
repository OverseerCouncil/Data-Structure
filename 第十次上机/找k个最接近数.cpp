#include<iostream>
#include<vector>

using namespace std;

vector<int> FindClosestEles(vector<int>& res, int k, int x)
{
	int left = 0;
	int right = res.size() - k;
	while (left < right)
	{
		int mid = (right + left) / 2;
		if (x - res[mid] > res[mid + k] - x)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	return vector<int>(res.begin() + left, res.begin() + k + left);
}

int main()
{
	vector<int> res;
	vector<int> output;
	int Input;
	int k, x;
	while (cin >> Input)
	{
		res.push_back(Input);
		if (cin.get() == '\n')
		{
			break;
		}
	}
	cin >> k;
	cin >> x;
	output = FindClosestEles(res, k, x);
	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i] << " ";
	}
}