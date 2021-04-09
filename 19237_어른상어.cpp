#include <iostream>

using namespace std;

struct s_space
{
	int num;
	int cnt;
	int shark_num;
};

struct s_shark
{
	int r;
	int c;
	int dir;
	bool alive;
};

int N;
int M;
int K;
s_space space[21][21];
s_shark shark[401];
int priority[401][5][4];
int remain;

void input()
{
	int i, j, k;
	int shark_num;

	cin >> N >> M >> K;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			cin >> shark_num;
			if (shark_num)
			{
				shark[shark_num].r = i;
				shark[shark_num].c = j;
				space[i][j].shark_num = shark_num;
			}
		}
	}
	for (i = 1; i <= M; i++)
	{
		cin >> shark[i].dir;
		shark[i].alive = true;
	}
	for (i = 1; i <= M; i++)
	{
		for (j = 1; j <= 4; j++)
		{
			for (k = 0; k < 4; k++)
			{
				cin >> priority[i][j][k];
			}
		}
	}
	remain = M;
}

bool in_range(s_shark s)
{
	if (s.r < 1 || s.r > N || s.c < 1 || s.c > N)
		return false;
	return true;
}

void spray_smell()
{
	int i;

	for (i = 1; i <= M; i++)
	{
		if (!shark[i].alive)
			continue;
		space[shark[i].r][shark[i].c].num = i;
		space[shark[i].r][shark[i].c].cnt = K;
	}
}

s_shark find_next(int num, int value)
{
	int i;
	int dr[] = {0, -1, 1, 0, 0};
	int dc[] = {0, 0, 0, -1, 1};
	s_shark curr, next;
	bool flag = false;

	curr = shark[num];
	for (i = 0; i < 4; i++)
	{
		next.alive = true;
		next.dir = priority[num][curr.dir][i];
		next.r = curr.r + dr[next.dir];
		next.c = curr.c + dc[next.dir];
		if (in_range(next) && space[next.r][next.c].num == value)
		{
			flag = true;
			break;
		}
	}
	if (!flag)
		next.dir = 0;
	return next;
}

void move()
{
	int i, j;
	s_shark next;

	for (i = 1; i <= M; i++)
	{
		if (!shark[i].alive)
		{
			continue;
		}
		next = find_next(i, 0);
		if (!next.dir)
		{
			next = find_next(i, i);
		}
		space[shark[i].r][shark[i].c].shark_num = 0;
		shark[i] = next;
		if (space[next.r][next.c].shark_num && space[next.r][next.c].shark_num < i)
		{
			shark[i].alive = false;
			remain--;
		}
		else if (space[next.r][next.c].shark_num > i)
		{
			shark[space[next.r][next.c].shark_num].alive = false;
			space[next.r][next.c].shark_num = i;
			remain--;
		}
		else
		{
			space[next.r][next.c].shark_num = i;
		}
	}
}

void remove_smell()
{
	int i, j;

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (space[i][j].cnt > 0)
				space[i][j].cnt--;
			if (space[i][j].cnt == 0)
				space[i][j].num = 0;
		}
	}
}

int solution()
{
	int t;
	int i, j;

	for (t = 1; t <= 1000; t++)
	{
		spray_smell();
		move();
		if (remain == 1)
			return t;
		remove_smell();
	}
	return -1;
}

int main()
{
	input();
	cout << solution() << endl;
	return 0;
}