using namespace std;

int select(int a[], int b[], int k);
int select(int a[], int loA, int hiA, int b[], int loB, int hiB, int k);

int A_SIZE = 7;
int B_SIZE = 7;

int main()
{
	int a[] = {2, 3, 4, 5, 6, 10, 22};
	int b[] = {7, 8, 9, 14, 15, 16, 17};

	//sorted = 2, 3, 4, 5, 6, 7, 8, 9, 10, 14, 15, 16, 17, 22
	//k = 5		           ^

	select(a, b, 5);
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
			return select(a, loA, i, b, loB, j, k);
		}
		else
		{
			return select(a, 0, A_SIZE - 1, b, 0, B_SIZE - 1, k);
		}
	}
	else
	{
		if (k <= i + j)
		{
			return select(a, i, hiA, b, loB, j, k);
		}
		else
		{
			return select(a, 0, A_SIZE - 1, b, 0, B_SIZE - 1, k);
		}
	}
}