#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isValid(string str)
{
	if ((str.size() > 1 && str[0] == '0') || stoi(str) > 255 || stoi(str) < 0)
	{
		return false;
	}
	return true;
}
void restore(string s, int k, string str, vector<string>& address)
{
	if (k == 0 && s.empty())
	{
		address.push_back(str);
	}
	else
	{
		for (int i = 1; i <= 3; i++)
		{
			if (s.size() >= i && isValid(s.substr(0, i)))
			{
				restore(s.substr(i), k - 1, str + s.substr(0, i) + (k == 1 ? "" : "."), address);
			}
		}
	}
}
vector<string> IsIpAddress(string s) 
{
	vector<string> address;
	if (s.size() > 12 || s.size() < 4) {
		return address;
	}
	restore(s, 4, "", address);
	return address;
}

int main()
{
	string Input;
	cin >> Input;
	vector<string> ValidIP;
	ValidIP = IsIpAddress(Input);
	for (int i=0; i < ValidIP.size(); i++)
	{
		cout << ValidIP[i] << endl;
	}
}