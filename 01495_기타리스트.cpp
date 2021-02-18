#include <iostream>
#include <cstring>

using namespace std;

int N;
int S;
int M;
int V[101];
int d[101][1001];

int dp(int n, int vol)
{
	if (vol < 0 || vol > M)
	{
		return -2;
	}
	if (n > N)
	{
		d[n][vol] = vol;
		return d[n][vol];
	}
	if (d[n][vol] != -1)
	{
		return d[n][vol];
	}
	d[n][vol] = max(dp(n + 1, vol - V[n]), dp(n + 1, vol + V[n]));
	return d[n][vol];
}

int main()
{
	int i, answer;

	cin >> N >> S >> M;
	for (i = 1; i <= N; i++)
	{
		cin >> V[i];
	}
	memset(d, -1, sizeof(d));
	answer = dp(1, S);
	if (answer != -2)
		cout << answer << endl;
	else
		cout << -1 << endl;
	return 0;
}