#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

struct pos
{
	int r;
	int c;
	int dir;
	int mirror;

	void init(int r, int c, int dir, int mirror)
	{
		this->r = r;
		this->c = c;
		this->dir = dir;
		this->mirror = mirror;
	}
};

int W;
int H;
int map[101][101];
pos src, dest;

int bfs()
{
	queue<pos> q;
	pos curr, next;
	int visit[101][101];
	int d[] = {-1, 1, 0, 0};
	int i;

	memset(visit, -1, sizeof(visit));
	curr = src;
	visit[curr.r][curr.c] = 0;
	for (i = 0; i < 4; i++)
	{
		curr.dir = i;
		q.push(curr);
	}
	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		for (i = 0; i < 4; i++)
		{
			next.init(curr.r + d[i], curr.c + d[3 - i], i, curr.mirror);
			if (next.r < 1 || next.r > H || next.c < 1 || next.c > W)
				continue;
			if (map[next.r][next.c])
				continue;
			if (curr.dir != next.dir)
				next.mirror++;
			if (visit[next.r][next.c] == -1 || visit[next.r][next.c] >= next.mirror)
			{
				visit[next.r][next.c] = next.mirror;
				q.push(next);
			}
		}
	}
	return visit[dest.r][dest.c];
}

int main()
{
	int i, j;
	string s;

	cin >> W >> H;
	for (i = 1; i <= H; i++)
	{
		cin >> s;
		for (j = 1; j <= W; j++)
		{
			if (s[j - 1] == '*')
				map[i][j] = 1;
			else if (s[j - 1] == 'C')
			{
				if (!src.r)
					src.init(i, j, 0, 0);
				else
					dest.init(i, j, 0, 0);
			}
		}
	}
	cout << bfs() << endl;
	return 0;
}