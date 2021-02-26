#include <iostream>

using namespace std;

int N;
long long X;
long long burger[51];
long long patty[51];

void init()
{
	int i;

	burger[0] = 1;
	patty[0] = 1;
	for (i = 1; i <= N; i++)
	{
		burger[i] = 1 + burger[i - 1] + 1 + burger[i - 1] + 1;
		patty[i]  = patty[i - 1] + 1 + patty[i - 1];
	}
}

long long ate(int n, long long x)
{
	if (n == 0)
	{
		if (x)
			return 1;
		else
			return 0;
	}
	if (x == 1)	
		return 0;
	else if (x <= 1 + burger[n - 1])
		return ate(n - 1, x - 1);
	else if (x == 1 + burger[n - 1] + 1)
		return patty[n - 1] + 1;
	else if (x <= 1 + burger[n - 1] + 1 + burger[n - 1])
		return patty[n - 1] + 1 + ate(n - 1, x - (1 + burger[n - 1] + 1));
	else
		return patty[n - 1] + 1 + patty[n - 1];
}

int main()
{
	cin >> N >> X;
	init();
	cout << ate(N, X) << endl;
	return 0;
}