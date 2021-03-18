#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pos
{
	int r;
	int c;

	void init(int r, int c)
	{
		this->r = r;
		this->c = c;
	}
};

int N;
int M;
int space[51][51];
int visit[51][51];
vector<pos> shark;

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
	int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int i, res = 0;

	for (i = 0; i < shark.size(); i++)
	{
		q.push(shark[i]);
	}
	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		res = max(res, visit[curr.r][curr.c]);
		for (i = 0; i < 8; i++)
		{
			next.init(curr.r + dr[i], curr.c + dc[i]);
			if (!in_range(next))
				continue;
			if (space[next.r][next.c])
				continue;
			if (visit[next.r][next.c])
				continue;
			visit[next.r][next.c] = visit[curr.r][curr.c] + 1;
			q.push(next);
		}
	}
	return res;
}

int main()
{
	int i, j;
	pos p;

	cin >> N >> M;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			cin >> space[i][j];
			if (space[i][j])
			{
				p.init(i, j);
				shark.push_back(p);
			}
		}
	}
	cout << bfs() << endl;
	return 0;
}