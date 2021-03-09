#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> NumVec;
int InPut;
int i,j,k,m;

int main()
{
	cin>>j;
	cin>>k;

	for(m=0;m<j;m++)
	{
		cin>>InPut;
		NumVec.push_back(InPut);
	}

	sort(NumVec.rbegin(),NumVec.rend());

	for(i=0;i<k;i++)
	{
		cout<<NumVec[i]<<" ";
	}

	cout<<endl;
	system("pause");
}
