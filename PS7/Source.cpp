#include <iostream>
#include <string>

using namespace std;

long gcd(long a, long b);
long exp(long x, long y, long N);
long inverse(long a, long N);
void ee(long a, long b);
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
			cin >> a;
			cin >> b;
			cout << gcd(a, b) << endl;
		}
		else if (type == "exp")
		{
			long x, y, N;
			cin >> x >> y >> N;
			cout << exp(x, y, N) << endl;
		}
		else if (type == "inverse")
		{
			long a, N;
			cin >> a >> N;
			long inv = inverse(a, N);
			if (inv == -1)
			{
				cout << "none" << endl;
			}
			else
			{
				cout << inv << endl;
			}
		}
		else if (type == "isprime")
		{
			long p;
			cin >> p;
			if (isprime(p))
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
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

long x, y, z; //pointers are hard :(

long inverse(long a, long N)
{
	ee(a, N);
	if (z == 1)
	{
		long ret = x % N;
		if (ret < 0)
		{
			return ret + N;
		}
		else
		{
			return ret;
		}
	}
	else
	{
		return -1;
	}
}

void ee(long a, long b)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		z = a;
		
	}
	else
	{
		ee(b, a%b);
		long x2 = y;
		long y2 = x - (a / b)*y;
		long z2 = z;
		x = x2;
		y = y2;
		z = z2;
		return;
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
	cout << N << " ";

	long phi = (p - 1)*(q - 1);

	long e = 2;
	for (e = 2; e < phi; e++)
	{
		if (gcd(e, phi) == 1)
		{
			cout << e << " ";
			break;
		}
	}

	long d = inverse(e, phi);
	cout << d << endl;
}

