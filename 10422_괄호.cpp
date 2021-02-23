#include <iostream>

#define MOD	1000000007

using namespace std;

long long m[5001];

void init()
{
	int i, j;

	m[0] = 1;
	for (i = 2; i <= 5000; i += 2)
	{
		for (j = 2; j <= i; j += 2)
		{
			m[i] += m[j - 2] * m[i - j];
			m[i] %= MOD;
		}
	}
}

int main()
{
	int t, T, L;

	init();
	cin >> T;
	for (t = 0; t < T; t++)
	{
		cin >> L;
		cout << m[L] << endl;
	}
	return 0;
}