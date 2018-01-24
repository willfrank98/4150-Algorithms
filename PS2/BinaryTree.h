#include <vector>

#pragma once
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(int maxSize);

	void add(int value);
	bool shapeIsEqual(BinaryTree other);
	std::vector<int> getTree();

	~BinaryTree();

private:
	std::vector<int> tree;
};

