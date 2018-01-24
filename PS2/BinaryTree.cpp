#include "BinaryTree.h"


BinaryTree::BinaryTree()
{
	
}

BinaryTree::BinaryTree(int maxSize)
{
	tree = new std::vector<int>(maxSize);
}

void BinaryTree::add(int value)
{

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
