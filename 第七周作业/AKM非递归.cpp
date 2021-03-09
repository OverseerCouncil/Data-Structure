#include<iostream>
#include<stack>

using namespace std;

int akm2(int m, int n)
{
	struct Node
	{
		int m, n, val;
	};
	stack<Node> expStack;
	Node init;
	init.m = m;
	init.n = n;
	init.val = -1;
	expStack.push(init);
	while (true)
	{
		Node& node = expStack.top();
		if (node.val != -1)
		{
			expStack.pop();
			if (expStack.empty())
			{
				return node.val;
			}
			else
			{
				Node& uncomputed = expStack.top();
				if (uncomputed.n == 1)
				{
					uncomputed.val = node.val;
				}
				else if (uncomputed.n == -1)
				{
					uncomputed.n = node.val;
				}
				else
				{
					uncomputed.val = node.val;
				}
			}
			continue;
		}
		if (node.m == 0)
		{
			node.val = node.n + 1;
		}
		else if (node.n == 0)
		{
			Node secondary;
			secondary.m = node.m - 1;
			secondary.n = 1;
			secondary.val = -1;
			expStack.push(secondary);
		}
		else
		{
			Node secondary;
			secondary.m = node.m - 1;
			secondary.n = -1;
			secondary.val = -1;
			expStack.push(secondary);
			Node triple;
			triple.m = node.m;
			triple.n = node.n - 1;
			triple.val = -1;
			expStack.push(triple);
			continue;
		}
	}
	return 0;
}

int main()
{
	int vr1, vr2;
	cout << "请输入数字一" << endl;
	cin >> vr1;
	cout << "请输入数字二" << endl;
	cin >> vr2;
	cout << akm2(vr1, vr2);
}