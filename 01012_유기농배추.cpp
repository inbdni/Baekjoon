#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T;
int N;
int M;
int K;
bool ground[51][51];
bool visited[51][51];

struct pos
{
	int y;
	int x;

	void init(int y, int x)
	{
		this->y = y;
		this->x = x;
	}

	bool in_range()
	{
		if (y < 0 || y >= N || x < 0 || x >= M)
			return false;
		return true;
	}
};

void bfs(int y, int x)
{
	queue<pos> q;
	pos curr, next;
	int d[] = {-1, 1, 0, 0};
	int i;

	curr.init(y, x);
	q.push(curr);
	visited[y][x] = true;
	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		for (i = 0; i < 4; i++)
		{
			next.init(curr.y + d[i], curr.x + d[3 - i]);
			if (!next.in_range())
				continue;
			if (!ground[next.y][next.x] || visited[next.y][next.x])
				continue;
			q.push(next);
			visited[next.y][next.x] = true;
		}
	}
}

int main()
{
	int t, k, x, y, cnt;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (t = 0; t < T; t++)
	{
		cin >> M >> N >> K;
		cnt = 0;
		memset(ground, false, sizeof(ground));
		memset(visited, false, sizeof(visited));
		for (k = 0; k < K; k++)
		{
			cin >> x >> y;
			ground[y][x] = true;
		}
		for (y = 0; y < N; y++)
		{
			for (x = 0; x < M; x++)
			{
				if (ground[y][x] && !visited[y][x])
				{
					cnt++;
					bfs(y, x);
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}