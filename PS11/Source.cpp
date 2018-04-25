#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int workout(int height, int index, int maxHeight);

vector<int> lengths;
vector<pair<char, int>> memory;
vector<pair<char, int>> confirmed;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int M;
		cin >> M;

		lengths = vector<int>(M);

		for (int j = 0; j < M; j++)
		{
			int length;

			cin >> length;
			lengths[j] = length;
		}

		memory = vector<pair<char, int>>(M, make_pair('!', INT32_MAX));
		confirmed = vector<pair<char, int>>(M, make_pair('!', INT32_MAX));
		string output = "";

		workout(0, 0, 0);

		if (memory[0].second == INT32_MAX)
		{
			output = "IMPOSSIBLE";
		}
		else
		{
			for (int j = 0; j < M; j++)
			{
				output += memory[j].first;
			}
		}
		

		cout << output << endl;
	}
}

int workout(int height, int index, int maxHeight)
{
	if (memory[index].first != '!')
	{
		return memory[index].second;
	}

	int retVal;
	char retChar;

	if (index == lengths.size() - 1)
	{
		if (height - lengths[index] != 0)
		{
			retVal = INT32_MAX;
			retChar = 'I';
		}
		else
		{
			retVal = maxHeight;
			retChar = 'D';
		}
	}
	else
	{
		int newMax;
		if (height + lengths[index] > maxHeight)
		{
			newMax = height + lengths[index];
		}
		else
		{
			newMax = maxHeight;
		}

		if (lengths[index] > height)
		{
			int h1 = workout(height + lengths[index], index + 1, newMax);

			retVal = h1;
			retChar = 'U';
		}
		else
		{
			int h1 = workout(height + lengths[index], index + 1, newMax);
			int h2 = workout(height - lengths[index], index + 1, maxHeight);

			if (h1 < h2)
			{
				retVal = h1;
				retChar = 'U';
			}
			else
			{
				retVal = h2;
				retChar = 'D';
			}
		}
	}

	if (retVal < memory[index].second)
	{
		memory[index] = pair<char, int>(retChar, retVal);
	}

	return retVal;
}