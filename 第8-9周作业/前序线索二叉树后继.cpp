#include<iostream>
#include<vector>

using namespace std;

struct BiThrNode
{
	char data;
	BiThrNode* lchild, * rchild;
	int ltag, rtag;
	BiThrNode(const char item) :data(item), lchild(NULL), rchild(NULL), ltag(0), rtag(0) {};
};

class BiThrTree
{
public:
	BiThrNode* root;
	void create();
	BiThrNode* nodeCreate(vector<char> Value, int len, int locate);
	void PreOrderThr(BiThrNode* root, BiThrNode*& prev);
};

void BiThrTree::create()
{
	char Input;
	int loc = 0;
	vector<char> Value;
	while (Input = cin.get())
	{
		if (Input == '\n')
		{
			break;
		}
		else
		{
			Value.push_back(Input);
		}
	}
	root = nodeCreate(Value, Value.size(), loc);
	BiThrNode* prev = NULL;
	PreOrderThr(root, prev);
}

BiThrNode* BiThrTree::nodeCreate(vector<char> Value, int len, int locate)
{
	if (Value.empty()) { return NULL; }
	BiThrNode* p = NULL;
	if (locate < len && Value[locate] != -1)
	{
		p = new BiThrNode(Value[locate]);
		p->lchild = nodeCreate(Value, len, 2 * locate + 1);
		p->rchild = nodeCreate(Value, len, 2 * locate + 2);
	}
	return p;
}

void BiThrTree::PreOrderThr(BiThrNode* root, BiThrNode*& prev)
{
	if (root == NULL)
	{
		return;
	}
	if (root->lchild == NULL)
	{
		root->lchild = prev;
		root->ltag = 1;
	}
	if (prev != NULL && prev->rchild == NULL)
	{   
		prev->rchild = root;
		prev->rtag = 1;
	}
	prev = root;
	if (root->ltag == 0)
		PreOrderThr(root->lchild, prev);
	if (root->rtag == 0)
		PreOrderThr(root->rchild, prev);
}

BiThrNode* PreOrderFindNext(BiThrTree T, BiThrNode* node)
{
	BiThrNode* cur = T.root;
	int rtTag = 0;
	while (cur)
	{
		while (cur->lchild != NULL && cur->ltag == 0)
		{
			if (cur == node) { rtTag = 1; }
			cur = cur->lchild;
			if (rtTag == 1) { return cur; }
		}
		if (cur->ltag == 1)
		{
			if (cur == node) { rtTag = 1; }
			cur = cur->rchild;
			if (rtTag == 1) { return cur; }
		}
		while (cur)
		{
			if (cur->lchild != NULL && cur->ltag == 0) { break; }
			if (cur == node) { rtTag = 1; }
			cur = cur->rchild;
			if (rtTag == 1) { return cur; }
		}
	}
	return NULL;
}