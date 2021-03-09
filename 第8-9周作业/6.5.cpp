//前序输出
template<class T>
void BinaryTree<T>::PreOrderPrint(BinTreeNode<T>* sub)
{
	if (sub != NULL)
	{
		cout << sub.value << " ";
		PreOrderPrint(sub.lChild);
		PreOrderPrint(sub.rChild);
	}
	return;
}

//后序输出
template<class T>
void BinaryTree<T>::PreOrderPrint(BinTreeNode<T>* sub)
{
	if (sub != NULL)
	{
		PreOrderPrint(sub.lChild);
		cout << sub.value << " ";
		PreOrderPrint(sub.rChild);
	}
	return;
}

//输出所有叶子节点
template<class T>
void BinaryTree<T>::PreOrderPrint(BinTreeNode<T>* sub)
{
	if (sub != NULL)
	{
		if (sub.lChild == NULL)
		{
			cout << sub.value << " ";
		}
		else
		{
			PreOrderPrint(sub.lChild);
		}
		PreOrderPrint(sub.rChild);
	}
	return;
}

//求次数,最终返回值为次数
template<class T>
void BinaryTree<T>::PreOrderPrint(BinTreeNode<T>* sub,int i)
{
	int j, k;
	if (sub != NULL)
	{
		j = PreOrderPrint(sub.lChild, i);
		k = PreOrderPrint(sub.rChild, i);
	}
	return (j > k) ? j : k;
}