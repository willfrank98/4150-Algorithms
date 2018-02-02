#include <iostream>

using namespace std;

int select(int a[], int b[], int k);
int select(int a[], int loA, int hiA, int b[], int loB, int hiB, int k);

int A_SIZE = 7;
int B_SIZE = 4;

int main()
{
	int a[] = { 2, 5, 7, 22 , 100, 101, 103};
	int b[] = { 7, 8, 9, 14 };

	int k = 9;

	cout << select(a, b, k);
}

int select(int a[], int b[], int k)
{
	return select(a, 0, A_SIZE - 1, b, 0, B_SIZE - 1, k);
}

int select(int a[], int loA, int hiA, int b[], int loB, int hiB, int k)
{
	if (hiA < loA)
	{
		return b[k - loA];
	}

	if (hiB < loB)
	{
		return a[k - loB];
	}

	int i = (loA + hiA) / 2;
	int j = (loB + hiB) / 2;

	if (a[i] > b[j])
	{
		if (k <= i + j)
		{
			return select(a, loA, i-1, b, loB, hiB, k);
		}
		else
		{
			return select(a, loA, hiA, b, j+1, hiB, k);
		}
	}
	else
	{
		if (k <= i + j)
		{
			return select(a, loA, hiA, b, loB, j-1, k);
		}
		else
		{
			return select(a, i+1, hiA, b, loB, hiB, k);
		}
	}
}