#include <iostream>
#include <string>

using namespace std;
unsigned int eChar[25];
string InPut;
unsigned int NoRptLong=1;
unsigned int i,j,k;

void CleanInt()
{
	for(j=0;j<25;j++)
	{
		eChar[j]=0;
	}
}

int main()
{
	cout<<"Please Input A Word"<<endl;
	cin>>InPut;

	CleanInt();

	for(i=0;i<InPut.length();i++)
	{
		for(k=i;k<InPut.length();k++)
		{
			if(eChar[InPut[k]-97]==0)
			{
				eChar[InPut[k]-97]=1;
			}
			else
			{
				if(k-i>NoRptLong)
				{
					NoRptLong=k-i;
				}
				k=InPut.length();
			}
		}
		CleanInt();
	}
	
	cout<<NoRptLong<<endl;

	system("pause");
}

