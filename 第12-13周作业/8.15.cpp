#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<stack<int>> NewPath(int v,int pre[],n)
{
	vector<stack<int>> V;
	V.resize(n);
	stack<int> S;
	for(int i=0;i<n;i++)
	{
		S.push(i+1);
		j=i+1;
		while(pre[j]!=v)
		{
			S.push(pre[j]);
			j=pre[j];
		}
		S.push(v);
		V[i]=S;
		S.clear();
	}
	return V;
}