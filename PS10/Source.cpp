#include <iostream>
#include <vector>

using namespace std;

int maxValue(int start, int uncloseable, int k);
int max(int vals[], int size);

vector<vector<int>> values;
vector<vector<vector<int>>> maxValues;

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
		maxValues = vector<vector<vector<int>>>(N, vector<vector<int>>(3, vector<int>(N, -1)));

		for (int i = 0; i < N; i++)
		{
			int val0, val1;
			cin >> val0 >> val1;

			values[i][0] = val0;
			values[i][1] = val1;
		}

		cout << maxValue(0, -1, k);
	}
}

int maxValue(int r, int uncloseable, int k)
{
	if (r == N)
	{
		return 0;
	}

	if (maxValues[r][uncloseable + 1][k] != -1)
	{
		return maxValues[r][uncloseable + 1][k];
	}

	int returnVal = 0;

	if (k == 0)
	{
		for (int i = r; i < N; i++)
		{
			returnVal += values[i][0] + values[i][1];
		}
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

	if (returnVal > maxValues[r][uncloseable + 1][k])
	{
		maxValues[r][uncloseable + 1][k] = returnVal;
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