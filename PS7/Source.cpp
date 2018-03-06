#include <iostream>
#include <string>

using namespace std;

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
			cout << isprime(p);
		}
		else if (type == "key")
		{
			long p, q;
			cin >> p >> q;
			cout << key(p, q);
		}
	}
}

long gcd(long a, long b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a%b);
	}
}

long exp(long x, long y, long N)
{
	while 
}

long inverse(long a, long N)
{

}

long isprime(long p)
{

}

long key(long p, long q)
{

}

