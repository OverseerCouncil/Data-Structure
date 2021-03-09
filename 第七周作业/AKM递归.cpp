#include<iostream>

using namespace std;

int akm(int m, int n)
{
	if (!m)
	{
		return n + 1;
	}
	if (!n)
	{
		return akm(m - 1, 1);
	}
	return akm(m - 1, akm(m, n - 1));
}

int main()
{
	int vr1, vr2;
	cout << "请输入数字一" << endl;
	cin >> vr1;
	cout << "请输入数字二" << endl;
	cin >> vr2;
	cout << akm(vr1, vr2);
}