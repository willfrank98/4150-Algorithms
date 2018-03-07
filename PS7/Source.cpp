#include <iostream>
#include <string>

using namespace std;

long gcd(long a, long b);
long exp(long x, long y, long N);
string inverse(long a, long N);
long* ee(long a, long b);
bool isprime(long p);
void key(long p, long q);

int main()
{
	while (!cin.eof())
	{
		string type;
		cin >> type;

		if (type == "gcd")
		{
			long a, b;
			cin >> a >> b;
			cout << gcd(a, b);
		}
		else if (type == "exp")
		{
			long x, y, N;
			cin >> x >> y >> N;
			cout << exp(x, y, N);
		}
		else if (type == "inverse")
		{
			long a, N;
			cin >> a >> N;
			cout << inverse(a, N);
		}
		else if (type == "isprime")
		{
			long p;
			cin >> p;
			if (isprime(p))
			{
				cout << "yes";
			}
			else
			{
				cout << "no";
			}
		}
		else if (type == "key")
		{
			long p, q;
			cin >> p >> q;
			key(p, q);
		}
	}
}

long gcd(long a, long b)
{
	while (b > 0)
	{
		long N = a % b;
		a = b;
		b = N;
	}
	return a;
}

long exp(long x, long y, long N)
{
	if (y == 0)
	{
		return 1;
	}
	else
	{
		long z = exp(x, y / 2, N);
		if (y % 2 == 0)
		{
			return (z * z) % N;
		}
		else
		{
			long temp = (z * z) % N;
			return (x * temp) % N;
		}
	}
}

string inverse(long a, long N)
{
	long* arr = ee(a, N);
	if (arr[2] == 1)
	{
		return "" + arr[0] % N;
	}
	else
	{
		return "none";
	}
}

long* ee(long a, long b)
{
	long temp[3];
	long* arr = temp;
	if (b == 0)
	{
		arr[0] = 1;
		arr[1] = 0;
		arr[2] = a;
		return arr;
	}
	else
	{
		arr = ee(b, a%b);
		long x = arr[1];
		long y = arr[0] - (a / b)*arr[1];
		long z = arr[2];
		arr[0] = x;
		arr[1] = y;
		arr[2] = z;
		return arr;
	}
}

bool isprime(long p)
{
	if (exp(2, p - 1, p) == 1 &&
		exp(3, p - 1, p) == 1 &&
		exp(5, p - 1, p) == 1)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void key(long p, long q)
{
	long N = p * q;
	cout << N;

	long phi = (p - 1)*(q - 1);

}

