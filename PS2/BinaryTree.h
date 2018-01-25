#include <vector>

using namespace std;

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
	void addSubMethod(int value, int pos);

	vector<int> tree;
	string treeString;
};

