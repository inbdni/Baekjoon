#include <iostream>
#include <queue>
#include <cstring>

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
bool map[51][51];

bool in_range(pos p)
{
	if (p.r < 0 || p.r >= N || p.c < 0 || p.c >= M)
		return false;
	return true;
}

int treasure_hunt(int r, int c)
{
	queue<pos> q;
	pos curr, next;
	bool visit[51][51];
	int d[] = {-1, 1, 0, 0};
	int i, s, size, cnt = 0;

	memset(visit, false, sizeof(visit));
	curr.init(r, c);
	visit[r][c] = true;
	q.push(curr);
	while (!q.empty())
	{
		size = q.size();
		for (s = 0; s < size; s++)
		{
			curr = q.front();
			q.pop();
			for (i = 0; i < 4; i++)
			{
				next.init(curr.r + d[i], curr.c + d[3 - i]);
				if (!in_range(next))
					continue;
				if (map[next.r][next.c] || visit[next.r][next.c])
					continue;
				visit[next.r][next.c] = true;
				q.push(next);
			}
		}
		cnt++;
	}
	return cnt - 1;
}

int main()
{
	int i, j, answer = 0;
	char c;

	cin >> N >> M;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			cin >> c;
			if (c == 'W')
				map[i][j] = 1;
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (!map[i][j])
				answer = max(answer, treasure_hunt(i, j));
		}
	}
	cout << answer << endl;
	return 0;
}