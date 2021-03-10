#include <iostream>
#include <queue>
#include <cstring>
#include <climits>

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
int space[20][20];
int visit[20][20];
pos shark, fish;
int shark_size;
int eaten_fish;

void bfs()
{
	queue<pos> q;
	pos curr, next;
	int d[] = {-1, 1, 0, 0};
	int i, fish_dist = INT_MAX;

	memset(visit, -1, sizeof(visit));
	fish.init(INT_MAX, INT_MAX);
	visit[shark.r][shark.c] = 0;
	q.push(shark);
	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		if (space[curr.r][curr.c] && space[curr.r][curr.c] < shark_size)
		{
			if (fish_dist > visit[curr.r][curr.c])
			{
				fish = curr;
				fish_dist = visit[curr.r][curr.c];
			}
			else if (fish_dist == visit[curr.r][curr.c])
			{
				if (fish.r > curr.r)
					fish = curr;
				else if (fish.r == curr.r && fish.c > curr.c)
					fish = curr;
			}
		}
		for (i = 0; i < 4; i++)
		{
			next.init(curr.r + d[i], curr.c + d[3 - i]);
			if (next.r < 0 || next.r >= N || next.c < 0 || next.c >= N)
				continue;
			if (space[next.r][next.c] > shark_size)
				continue;
			if (visit[next.r][next.c] != -1)
				continue;
			visit[next.r][next.c] = visit[curr.r][curr.c] + 1;
			q.push(next);
		}
	}
}

int main()
{
	int i, j;
	int answer = 0;

	cin >> N;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> space[i][j];
			if (space[i][j] == 9)
			{
				shark.init(i, j);
				shark_size = 2;
				space[i][j] = 0;
			}
		}
	}
	while (1)
	{
		bfs();
		if (fish.r == INT_MAX)
			break;
		eaten_fish++;
		if (eaten_fish == shark_size)
		{
			shark_size++;
			eaten_fish = 0;
		}
		shark = fish;
		space[fish.r][fish.c] = 0;
		answer += visit[fish.r][fish.c];		
	}
	cout << answer << endl;
	return 0;
}