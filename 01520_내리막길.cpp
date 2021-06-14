#include <iostream>

using namespace std;

int M;
int N;
int map[500][500];
bool visit[500][500];
long long mem[500][500];

void dp(int m, int n)
{
	int i, dm, dn;
	int d[] = {-1, 1, 0, 0};

	visit[m][n] = true;
	for (i = 0; i < 4; i++)
	{
		dm = m + d[i];
		dn = n + d[3 - i];
		if (dm < 0 || dm >= M || dn < 0 || dn >= N)
			continue;
		if (map[m][n] >= map[dm][dn])
			continue;
		if (!visit[dm][dn])
			dp(dm, dn);
		mem[m][n] += mem[dm][dn];
	}
}

int main()
{
	int i, j;

	cin >> M >> N;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	visit[0][0] = true;
	mem[0][0] = 1;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (!visit[i][j])
				dp(i, j);
		}
	}
	cout << mem[M - 1][N - 1] << endl;
	return 0;
}