#include <iostream>

using namespace std;

int N;
int M;
int A[501][501];
bool visited[501][501];
int d[] = {-1, 1, 0, 0};
int answer;

void dfs(int x, int y, int cnt, int sum)
{
	int i, dx, dy;

	sum += A[y][x];
	if (cnt == 4)
	{
		answer = max(answer, sum);
		return;
	}
	visited[y][x] = 1;
	for (i = 0; i < 4; i++)
	{
		dx = x + d[i];
		dy = y + d[3 - i];
		if (dx > 0 && dx <= M && dy > 0 && dy <= N && !visited[dy][dx])
			dfs(dx, dy, cnt + 1, sum);
	}
	visited[y][x] = 0;
}

void other(int x, int y)
{
	if (x > 1 && x < M)
	{
		if (y > 1) 
			answer = max(answer, A[y][x - 1] + A[y][x] + A[y][x + 1] + A[y - 1][x]);
		if (y < N)
			answer = max(answer, A[y][x - 1] + A[y][x] + A[y][x + 1] + A[y + 1][x]);
	}
	if (y > 1 && y < N)
	{
		if (x > 1)
			answer = max(answer, A[y - 1][x] + A[y][x] + A[y + 1][x] + A[y][x - 1]);
		if (x < M)
			answer = max(answer, A[y - 1][x] + A[y][x] + A[y + 1][x] + A[y][x + 1]);
	}
}

int main()
{
	int i, j;

	cin >> N >> M;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			cin >> A[i][j];
		}
	}
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			dfs(j, i, 1, 0);
			other(j, i);
		}
	}
	cout << answer << endl;
	return 0;
}