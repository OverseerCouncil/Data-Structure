#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<int> Array;
vector<int> Sort;

int main()
{
	int Input;
	int mid;
	size_t i, j, k;

	cout << "以空格为分割，回车为结束" << endl;
	while (cin >> Input)
	{
		Array.push_back(Input);
		if (cin.get() == '\n')
		{
			break;
		}
	}

	cout << "输入窗口大小k";
	cin >> k;
	for (i = 0; i < Array.size() - k + 1; i++)
	{
		cout << "[";
		for (j = 0; j < k-1; j++)
		{
			cout << Array.at(i + j) << ",";
			Sort.push_back(Array[i + j]);
		}
		cout << Array[i + k - 1] << "]";
		Sort.push_back(Array[i + k - 1]);
		sort(Sort.begin(), Sort.end());
		if (k % 2)
		{
			mid = Sort[k / 2];
			cout << ", k=" << mid << endl;
		}
		else
		{
			mid = Sort[k / 2 - 1] + Sort[k / 2];
			mid = mid / 2;
			cout << ", k=" << mid << endl;
		}
		Sort.clear();
	}
	system("pause");
}