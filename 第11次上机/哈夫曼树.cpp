#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct HuffmanNode
{
	int value;
	HuffmanNode* lChild;
	HuffmanNode* rChild;
	HuffmanNode(int elem) :lChild(NULL), rChild(NULL), value(elem) {};
};

bool cmp(const HuffmanNode* n1, const HuffmanNode* n2)
{
	return n1->value < n2->value;
}

class HuffmanTree
{
public:
	HuffmanNode* root;
	HuffmanTree() {};
	void create()
	{
		vector<int> value;
		vector<HuffmanNode*> Node;
		HuffmanNode* t1, * t2, * pr;
		int n;
		int temp;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			value.push_back(temp);
			if (cin.get() == '\n') { break; }
		}
		sort(value.begin(), value.end());
		for (int j = 0; j < value.size(); j++)
		{
			HuffmanNode* temp = new HuffmanNode(value[j]);
			Node.push_back(temp);
		}
		sort(Node.begin(), Node.end(), cmp);

		while (Node.size() != 1)
		{
			t1 = Node[0];
			t2 = Node[1];
			pr = new HuffmanNode(t1->value + t2->value);
			pr->lChild = t1;
			pr->rChild = t2;
			Node.push_back(pr);
			Node.erase(Node.begin());
			Node.erase(Node.begin());
			sort(Node.begin(), Node.end(), cmp);
		}
		root = Node[0];
	}
	int KVL(HuffmanNode* sub, int n)
	{
		int left = 0;
		int right = 0;
		if (sub->lChild == NULL && sub->rChild == NULL)
		{
			return sub->value * n;
		}
		else
		{
			left = KVL(sub->lChild, n + 1);
			right = KVL(sub->rChild, n + 1);
			int x = left + right;
			return x;
		}
	}
};

int main()
{
	HuffmanTree Tree;
	Tree.create();
	cout << Tree.KVL(Tree.root, 0) << endl;
}