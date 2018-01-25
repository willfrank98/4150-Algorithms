#include "BinaryTree.h"
#include <cmath>


BinaryTree::BinaryTree()
{
	
}

BinaryTree::BinaryTree(int maxSize)
{
	int size = pow(2, maxSize) - 1;
	tree = vector<int>(size);

	treeString = string(size, '0');
}

void BinaryTree::add(int value)
{
	int pos = tree.size() / 2 + 1;

	if (tree[pos] == 0)
	{
		tree[pos] = value;
		treeString[pos] = '1';
		return;
	}
	else if (value > tree[pos])
	{
		return addSubMethod(value, pos + (pos / 2));
	}
	else
	{
		return addSubMethod(value, pos - (pos / 2));
	}
}

void BinaryTree::addSubMethod(int value, int pos)
{
	if (tree[pos] == 0)
	{
		tree[pos] = value;
		treeString[pos] = '1';
		return;
	}
	else if (value > tree[pos])
	{
		return addSubMethod(value, pos + (pos / 2));
	}
	else
	{
		return addSubMethod(value, pos - (pos / 2));
	}
}

bool BinaryTree::shapeIsEqual(BinaryTree other)
{
	std::vector<int> otherTree = other.getTree();
	if (tree.size() != otherTree.size())
	{
		return false;
	}


	return false;
}

std::vector<int> BinaryTree::getTree()
{
	return tree;
}


BinaryTree::~BinaryTree()
{
}
