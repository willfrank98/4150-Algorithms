#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

vector<int> tree;
string treeString;

void add(int value);
void addSubMethod(int value, int pos, int increment);

int main()
{
	int ceilings;
	cin >> ceilings;

	int layers;
	cin >> layers;

	map<string, int> trees;
	int differentTreeShapes = 0;

	for (int i = 0; i < ceilings; i++)
	{
		int size = pow(2, layers) - 1;
		tree = vector<int>(size, 0);
		treeString = string(size, '0');

		for (int j = 0; j < layers; j++)
		{
			int input;
			cin >> input;

			add(input);
		}

		if (trees[treeString] == 0)
		{
			trees[treeString]++;
			differentTreeShapes++;
		}

	}
	
	cout << differentTreeShapes;
}

void add(int value)
{
	int pos = tree.size() / 2;

	if (tree[pos] == 0)
	{
		tree[pos] = value;
		treeString[pos] = '1';
		return;
	}

	int increment = (pos / 2) + 1;
	if (value > tree[pos])
	{
		return addSubMethod(value, pos + increment, increment);
	}
	else
	{
		return addSubMethod(value, pos - increment, increment);
	}
}

void addSubMethod(int value, int pos, int increment)
{
	if (tree[pos] == 0)
	{
		tree[pos] = value;
		treeString[pos] = '1';
		return;
	}

	increment /= 2;
	if (value > tree[pos])
	{
		return addSubMethod(value, pos + increment, increment);
	}
	else
	{
		return addSubMethod(value, pos - increment, increment);
	}
}