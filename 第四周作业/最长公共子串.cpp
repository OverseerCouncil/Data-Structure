#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;

const int nInitLen = 1024;

class MyString
{
private:
	int nLen;
	char* ch;
public:
	MyString();
	~MyString();
	MyString(const char* chSrc);
	int GetLen()const { return nLen; }
	char operator[](int nPos)const;
};

MyString::MyString()
{
	nLen = 0;
	ch = new char[nInitLen + 1];
	if (!ch) { cerr << "Allocate Error!\n"; return; }
	ch[0] = '\0';
}
MyString::MyString(const char* chSrc)
{
	int i = 0;
	nLen = strlen(chSrc);
	if (nLen > nInitLen)
	{
		ch = new char[nLen + 1];
	}
	else
	{
		ch = new char[nInitLen + 1];
	}
	if (!ch) { cerr << "Allocate Error!\n"; return; }
	while (chSrc[i] != '\0')
	{
		ch[i] = chSrc[i];
		i++;
	}
	ch[i] = '\0';
}

MyString::~MyString()
{
	delete[]ch;
}

char MyString::operator[](int nPos)const
{
	if (nPos < 0 && nPos >= nLen)
	{
		cerr << "nPos Out Of Bounds!" << endl; return 0;
	}
	return ch[nPos];
}

int main()
{
	char tempA[1024];
	cin >> tempA;
	MyString S(tempA);
	char tempB[1024];
	cin >> tempB;
	MyString T(tempB);
	int hashMap[32][32] = { 0 };
	int biggest = 0;
	char longest[64];
	for (int i = 1; i <= S.GetLen(); i++)
	{
		for (int j = 1; j <= T.GetLen(); j++)
		{
			if (S[i - 1] == T[j - 1])
			{
				hashMap[i][j] = hashMap[i - 1][j - 1] + 1;
				if (hashMap[i][j] > biggest)
				{
					biggest = hashMap[i][j];
					for (int k = biggest; k > 0; k--)
					{
						longest[biggest - k] = T[j - k];
					}
					longest[biggest] = '\0';
				}
			}
			else
			{
				hashMap[i][j] = 0;
			}
		}
	}
	cout << longest;
}