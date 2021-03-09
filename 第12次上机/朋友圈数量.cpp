#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> M;

int find(int x, vector<int>& p)
{
	return p[x] == x ? x : p[x] = find(p[x], p);
}

int main()
{
	M.resize(1);
	char temp;
	int j = 0;
	while (1)
	{
		temp = cin.get();
		if (temp == '\n')
		{
			break;
		}
		else if (temp == '1' || temp == '0')
		{
			M[j].push_back(temp - 48);
		}
		else if (temp == ']' && cin.get() != ']')
		{
			j++;
			M.resize(M.size() + 1);
		}
	}
	vector<int>pre(M.size());
	for (int i = 0; i < M.size(); i++)
	{
		pre[i] = i;
	}
	int group = M.size();
	for (int i = 0; i < M.size(); i++)
	{
		for (int j = 0; j < M.size(); j++)
		{
			if (i != j && M[i][j] == 1)
			{
				int a = find(i, pre);
				int b = find(j, pre);
				if (a != b)
				{
					pre[a] = b;
					group--;
				}
			}
		}
	}
	cout << group;
}