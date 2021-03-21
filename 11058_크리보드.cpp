#include <iostream>

using namespace std;

int N;
long long m[101];

void dp()
{
	int i, j;

	for (i = 1; i <= N; i++)
	{
		m[i] = m[i - 1] + 1;
		for (j = 3; j < i; j++)
			m[i] = max(m[i], m[i - j] * (j - 1));
	}
}

int main()
{
	cin >> N;
	dp();
	cout << m[N] << endl;
	return 0;
}