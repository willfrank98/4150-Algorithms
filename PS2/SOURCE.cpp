#include <iostream>
#include <map>
#include "BinaryTree.h"

using namespace std;

int main()
{
	int ceilings;
	cin >> ceilings;

	int layers;
	cin >> layers;

	map<string, int> tree;

	for (int i = 0; i < ceilings; i++)
	{
		BinaryTree t(layers);

		for (int j = 0; j < layers; j++)
		{
			int input;
			cin >> input;

			t.add(input);
		}
	}
}