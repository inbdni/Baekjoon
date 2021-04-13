#include <iostream>

using namespace std;

long long S;

int main()
{
	long long s, m, e;
	long long n, sum;

	cin >> S;
	s = 1;
	e = S;
	while (s <= e)
	{
		m = (s + e) / 2;
		sum = m * (m + 1) / 2;
		if (sum <= S)
		{
			n = m;
			s = m + 1;
		}
		else
		{
			e = m - 1;
		}	
	}
	cout << n << endl;
	return 0;
}