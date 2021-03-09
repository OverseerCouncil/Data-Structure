#include<iostream>
#include<stack>

using namespace std;

struct brick
{
	int n;
	char depart;
	char pass;
	char destn;
};

void hanoi(int n, char depart, char pass, char destn)
{
	stack<brick> s;
	brick out = { n,depart,pass,destn };
	while (!(out.n == 0 && s.empty()))
	{
		brick in = out;
		while (in.n > 0)
		{
			s.push(in);
			in.n--;
			swap(in.pass, in.destn);
		}
		out = s.top();
		s.pop();
		cout << "move " << out.n << " from " << out.depart << " to " << out.destn << endl;
		out.n--;
		swap(out.depart, out.pass);
	}
}

int main()
{
	int n;
	cout << "请输入n大小";
	cin >> n;
	hanoi(n, 'A', 'B', 'C');
}