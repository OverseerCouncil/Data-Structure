#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int NumMax, NumMin, n, i, j,temp;

int main()
{
	vector<int>Num;
	cout << "Please Enter the N" << endl;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "Please Enter Num" << i + 1 << endl;
		cin >> temp;
		Num.push_back(temp);
	}
	NumMax = INT_MIN; NumMin = INT_MAX;
	for (j = 0; j < n/2; j++)
	{
		if (Num[2*j] <= Num[2*j + 1])
		{
			if (Num[2*j] < NumMin)
			{
				NumMin = Num[2*j];
			}
			if (Num[2*j + 1] > NumMax)
			{
				NumMax = Num[2*j + 1];
			}
		}
		else
		{
			if (Num[2*j + 1] < NumMin)
			{
				NumMin = Num[2*j];
			}
			if (Num[2*j] > NumMax)
			{
				NumMax = Num[2*j + 1];
			}
		}
	}
	if (n % 2)
	{
		if (Num[n-1] < NumMin)
		{
			NumMin = Num[n-1];
		}
		if (Num[n-1] > NumMax)
		{
			NumMax = Num[n-11];
		}
	}
	cout << "The Max is" << NumMax << endl;
	cout << "The Min is" << NumMin << endl;
	system("pause");
}
