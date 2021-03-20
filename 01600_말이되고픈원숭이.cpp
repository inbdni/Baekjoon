#include <iostream>
#include <queue>

using namespace std;

struct pos
{
	int r;
	int c;
	int be_horse;

	void init(int r, int c, int be_horse)
	{
		this->r = r;
		this->c = c;
		this->be_horse = be_horse;
	}
};

int K;
int H;
int W;
int board[201][201];
int visit[201][201][31];

bool in_range(pos p)
{
	if (p.r < 1 || p.r > H || p.c < 1 || p.c > W)
		return false;
	return true;
}

int bfs()
{
	queue<pos> q;
	pos curr, next;
	int d[] = {-1, 1, 0, 0};
	int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
	int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};
	int i;

	next.init(1, 1, 0);
	visit[next.r][next.c][next.be_horse] = 1;
	q.push(next);
	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		if (curr.r == H && curr.c == W)
		{
			return visit[curr.r][curr.c][curr.be_horse] - 1;
		}
		for (i = 0; i < 4; i++)
		{
			next.init(curr.r + d[i], curr.c + d[3 - i], curr.be_horse);
			if (!in_range(next))
				continue;
			if (board[next.r][next.c])
				continue;
			if (visit[next.r][next.c][next.be_horse])
				continue;
			visit[next.r][next.c][next.be_horse] = visit[curr.r][curr.c][curr.be_horse] + 1;
			q.push(next);
		}
		if (curr.be_horse == K)
		{
			continue;
		}
		for (i = 0; i < 8; i++)
		{
			next.init(curr.r + dr[i], curr.c + dc[i], curr.be_horse + 1);
			if (!in_range(next))
				continue;
			if (board[next.r][next.c])
				continue;
			if (visit[next.r][next.c][next.be_horse])
				continue;
			visit[next.r][next.c][next.be_horse] = visit[curr.r][curr.c][curr.be_horse] + 1;
			q.push(next);
		}
	}
	return -1;
}

int main()
{
	int i, j;

	cin >> K >> W >> H;
	for (i = 1; i <= H; i++)
	{
		for (j = 1; j <= W; j++)
		{
			cin >> board[i][j];
		}
	}
	cout << bfs() << endl;
	return 0;
}