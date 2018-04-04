#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int penalty(int start);

vector<int> penalties;
vector<int> hotels;
int endIndex;

int main()
{
	int n;
	cin >> n;

	endIndex = n;

	penalties = vector<int>(n, -1);
	hotels = vector<int>(n + 1);

	for (int i = 0; i < n+1; i++)
	{
		int dis;
		cin >> dis;

		hotels[i] = dis;
	}

	cout << penalty(0);
}

int penalty(int start)
{
	if (start == endIndex)
	{
		return 0;
	}

	if (penalties[start] != -1)
	{
		return penalties[start];
	}

	int min = INT32_MAX;

	for (int i = start + 1; i < endIndex + 1; i++)
	{
		int initialPen = pow((400 - (hotels[i] - hotels[start])), 2);
		int otherPen = penalty(i);
		int pen = initialPen + otherPen;

		if (pen < min)
		{
			min = pen;
		}
	}

	penalties[start] = min;
	return min;
}