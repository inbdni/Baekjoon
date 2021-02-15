#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N;
int M;
int map[1001][1001];
int dp[1001][1001][2];
int d[] = {-1, 1, 0, 0};

int bfs()
{
	queue< pair<int, pair<int, int> > > q;
	int flag;
	int i;
	int x, y, dx, dy;

	dp[1][1][0] = 1;
	q.push(make_pair(0, make_pair(1, 1)));
	while (!q.empty())
	{
		flag = q.front().first;
		x = q.front().second.first;
		y = q.front().second.second;
		q.pop();
		if (x == M && y == N)
		{
			return dp[y][x][flag];
		}
		for (i = 0; i < 4; i++)
		{
			dx = x + d[i];
			dy = y + d[3 - i];
			if (!(dx > 0 && dx <= M && dy > 0 && dy <= N))
			{
				continue;
			}
			if (dp[dy][dx][flag])
			{
				continue;
			}
			if (map[dy][dx] == 0)
			{
				dp[dy][dx][flag] = dp[y][x][flag] + 1;
				q.push(make_pair(flag, make_pair(dx, dy)));
			}
			if (map[dy][dx] == 1 && !flag)
			{
				dp[dy][dx][1] = dp[y][x][flag] + 1;
				q.push(make_pair(1, make_pair(dx, dy)));
			}
		}
	}
	return -1;
}

int main()
{
	int i, j;
	string s;

	cin >> N >> M;
	for (i = 1; i <= N; i++)
	{
		cin >> s;
		for (j = 1; j <= M; j++)
		{
			map[i][j] = s[j - 1] - '0';
		}
	}
	cout << bfs() << endl;
	return 0;
}