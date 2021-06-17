#include <iostream>
#include <cstring>
#include <queue>

#define	EAST	1
#define	WEST	2
#define	SOUTH	3
#define	NORTH	4

#define	L	4
#define	R	5

using namespace std;

struct pos
{
	int r;
	int c;
	int d;
};

int M;
int N;
int board[101][101];
pos src, dst;

bool in_range(pos p)
{
	if (p.r <= 0 || p.r > M || p.c <= 0 || p.c > N)
		return false;
	return true;
}

pos go(pos curr, int k)
{
	int i;
	int dr[] = {0, 0, 0, 1, -1};
	int dc[] = {0, 1, -1, 0, 0};
	pos next = curr;

	for (i = 0; i < k; i++)
	{
		next.r += dr[next.d];
		next.c += dc[next.d];
		if (!in_range(next) || board[next.r][next.c])
			return curr;
	}
	return next;
}

pos turn(pos curr, int dir)
{
	int i;
	int d[] = {NORTH, EAST, SOUTH, WEST};
	pos next = curr;

	for (i = 0; i < 4; i++)
		if (d[i] == next.d)
			break;
	if (dir == L && --i < 0)
		i = 3;
	else if (dir == R && ++i > 3)
		i = 0;
	next.d = d[i];
	return next;
}

int bfs()
{
	queue<pos> q;
	pos curr, next;
	bool visit[101][101][5];
	int i, s, size, cnt = 0;

	memset(visit, false, sizeof(visit));
	curr = src;
	visit[curr.r][curr.c][curr.d] = true;
	q.push(curr);
	while (!q.empty())
	{
		size = q.size();
		for (s = 0; s < size; s++)
		{
			curr = q.front();
			q.pop();
			if (curr.r == dst.r && curr.c == dst.c && curr.d == dst.d)
				return cnt;
			for (i = 1; i <= 5; i++)
			{
				if (i <= 3)
					next = go(curr, i);
				else
					next = turn(curr, i);
				if (!in_range(next))
					continue;
				if (board[next.r][next.c])
					continue;
				if (visit[next.r][next.c][next.d])
					continue;
				visit[next.r][next.c][next.d] = true;
				q.push(next);
			}
		}
		cnt++;
	}
	return -1;
}

int main()
{
	int i, j;

	cin >> M >> N;
	for (i = 1; i <= M; i++)
	{
		for (j = 1; j <= N; j++)
		{
			cin >> board[i][j];
		}
	}
	cin >> src.r >> src.c >> src.d;
	cin >> dst.r >> dst.c >> dst.d;
	cout << bfs() << endl;
	return 0;
}