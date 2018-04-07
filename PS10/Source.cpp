#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int maxValue(int start, int uncloseable, int k);
int max(int vals[], int size);

vector<vector<int>> values;
map<string, int> maxValues;
//vector<vector<vector<int>>> maxValues;

int N;

int main()
{
	while (true)
	{
		int k;
		cin >> N >> k;

		if (N == 0 && k == 0)
		{
			return 0;
		}

		values = vector<vector<int>>(N, vector<int>(2, 0));
		maxValues = map<string, int>();

		for (int i = 0; i < N; i++)
		{
			int val0, val1;
			cin >> val0 >> val1;

			values[i][0] = val0;
			values[i][1] = val1;
		}

		cout << maxValue(0, -1, k) << endl << endl;
	}
}

int maxValue(int r, int uncloseable, int k)
{
	//maxValues = vector<vector<vector<int>>>(N, vector<vector<int>>(3, vector<int>(N, -1))); [r][uncloseable + 1][k]
	//map<string, int> maxValues;
	//vector<vector<vector<int>>> maxValues(N, vector<vector<int>>(3, vector<int>(N, -1)));

	if (r == N)
	{
		return 0;
	}

	string temp = to_string(r) + to_string(uncloseable) + to_string(k);
	if (maxValues[temp] != 0)
	{
		if (maxValues[temp] == -1)
		{
			return 0;
		}
		return maxValues[temp];
	}

	int returnVal = 0;

	if (k == 0)
	{
		returnVal = values[r][0] + values[r][1] + maxValue(r + 1, -1, k);
	}
	else if (k == N - r)
	{
		if (uncloseable == 0)
		{
			returnVal = values[r][0] + maxValue(r + 1, 0, k - 1);
		}
		else if (uncloseable == 1)
		{
			returnVal = values[r][1] + maxValue(r + 1, 1, k - 1);
		}
		else
		{
			int o1 = values[r][0] + maxValue(r + 1, 0, k - 1);
			int o2 = values[r][1] + maxValue(r + 1, 1, k - 1);

			int temp[2] = { o1, o2 };

			returnVal = max(temp, 2);
		}
	}
	else
	{
		if (uncloseable == 0)
		{
			int o1 = values[r][0] + maxValue(r + 1, 0, k - 1);
			int o2 = values[r][0] + values[r][1] + maxValue(r + 1, -1, k);

			int temp[2] = { o1, o2 };

			returnVal = max(temp, 2);
		}
		else if (uncloseable == 1)
		{
			int o1 = values[r][1] + maxValue(r + 1, 1, k - 1);
			int o2 = values[r][0] + values[r][1] + maxValue(r + 1, -1, k);

			int temp[2] = { o1, o2 };

			returnVal = max(temp, 2);
		}
		else
		{
			int o1 = values[r][0] + maxValue(r + 1, 0, k - 1);
			int o2 = values[r][1] + maxValue(r + 1, 1, k - 1);
			int o3 = values[r][0] + values[r][1] + maxValue(r + 1, -1, k);

			int temp[3] = { o1, o2, o3 };

			returnVal = max(temp, 3);
		}
	}

	if (returnVal == 0)
	{
		maxValues[temp] = -1;
	}
	else if (returnVal > maxValues[temp])
	{
		maxValues[temp] = returnVal;
	}

	return returnVal;
}

int max(int vals[], int size)
{
	int temp = -1;

	for (int i = 0; i < size; i++)
	{
		if (vals[i] > temp)
		{
			temp = vals[i];
		}
	}

	return temp;
}