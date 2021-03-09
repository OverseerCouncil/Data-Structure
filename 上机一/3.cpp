#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> StrVec;
string TempStr;
string StrCpr;
unsigned int AChar[26] = { 0 };
unsigned int BChar[26] = { 0 };
unsigned int StrLength;
unsigned int i,j,k,m,n;
char ch;

void CleanChar()
{
	for (i = 0; i < 26; i++)
	{
		AChar[i] = 0;
	}
}

int main()
{
	while (cin >> TempStr)
	{
		if ((ch=getchar())=='\n')
		{
			break;
		}
		StrVec.push_back(TempStr);
	}

	cin >> StrCpr;
	for (m = 0; m < StrCpr.length(); m++)
	{
		BChar[StrCpr[m] - 97]++;
	}
	
	for (j = 0; j < StrVec.size(); j++)
	{
		for (k = 0; k < StrVec[j].length(); k++)
		{
			AChar[StrVec[j][k] - 97]++;
		}
		for (n = 0; n < 26; n++)
		{
			if (AChar[n] > BChar[n])
			{
				n = 27;
			}
		}
		if (n == 26)
		{
			StrLength += StrVec[j].size();
		}
		CleanChar();
	}

	cout << StrLength << endl;
	system("pause");
}