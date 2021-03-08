#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct pos
{
	int r;
	int c;
	int destroy;
	bool day;

	void init(int r, int c, int destroy, bool day)
	{
		this->r = r;
		this->c = c;
		this->destroy = destroy;
		this->day = day;
	}
};

int N;
int M;
int K;
int map[1001][1001];
int dp[1001][1001][11][2];
int d[] = {-1, 1, 0, 0};

bool in_range(pos p)
{
	if (p.r < 1 || p.r > N || p.c < 1 || p.c > M)
		return false;
	return true;
}

int bfs()
{
	queue<pos> q;
	pos curr, next;
	int i;

	next.init(1, 1, 0, true);
	dp[next.r][next.c][next.destroy][next.day] = 1;
	q.push(next);
	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		if (curr.r == N && curr.c == M)
		{
			return dp[curr.r][curr.c][curr.destroy][curr.day];
		}
		for (i = 0; i < 4; i++)
		{
			next.init(curr.r + d[i], curr.c + d[3 - i], curr.destroy, !curr.day);
			if (!in_range(next))
			{
				continue;
			}
			if (map[next.r][next.c])
			{
				if (curr.destroy >= K)
				{
					continue;
				}
				if (curr.day)
				{
					next.destroy++;
				}
				else
				{
					next.r -= d[i];
					next.c -= d[3 - i];
				}
			}
			if (dp[next.r][next.c][next.destroy][next.day])
			{
				continue;
			}
			dp[next.r][next.c][next.destroy][next.day] = dp[curr.r][curr.c][curr.destroy][curr.day] + 1;
			q.push(next);
		}
	}
	return -1;
}

int main()
{
	int i, j;
	string s;

	cin >> N >> M >> K;
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