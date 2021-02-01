#include <iostream>
#include <vector>
#include <cstring>

#define UP		1
#define DOWN	2
#define	RIGHT	3
#define	LEFT	4

using namespace std;

typedef struct s_shark
{
	int r;
	int c;
	int s;
	int d;
	int z;
	int alive;
} t_shark;

int R;
int C;
int M;
vector<t_shark> shark;
int area[101][101];
int dy[] = {0, -1, 1, 0, 0};
int dx[] = {0, 0, 0, 1, -1};


int fishing(int col)
{
	int i;
	int res = 0;

	for (i = 1; i <= R; i++)
	{
		if (area[i][col])
		{
			res = shark[area[i][col]].z;
			shark[area[i][col]].alive = 0;
			area[i][col] = 0;
			break;
		}
	}
	return res;
}

void move(int idx)
{
	int i;

	for (i = 1; i <= shark[idx].s; i++)
	{
		if (shark[idx].d == UP && shark[idx].r == 1)
			shark[idx].d = DOWN;
		else if (shark[idx].d == DOWN && shark[idx].r == R)
			shark[idx].d = UP;
		else if (shark[idx].d == RIGHT && shark[idx].c == C)
			shark[idx].d = LEFT;	
		else if (shark[idx].d == LEFT && shark[idx].c == 1)
			shark[idx].d = RIGHT;
		shark[idx].r += dy[shark[idx].d];
		shark[idx].c += dx[shark[idx].d];
	}
}

void moving()
{
	int i, j;
	int x, y;
	int tmp[R + 1][C + 1];

	memset(tmp, 0, sizeof(tmp));
	for (i = 1; i <= M; i++)
	{
		if (!shark[i].alive)
			continue;
		move(i);
		y = shark[i].r;
		x = shark[i].c;
		if (tmp[y][x])
		{
			if (shark[tmp[y][x]].z < shark[i].z)
			{
				shark[tmp[y][x]].alive = 0;
				tmp[y][x] = i;
			}
			else
			{
				shark[i].alive = 0;
			}
		}
		else
		{
			tmp[y][x] = i;
		}
	}
	memset(area, 0, sizeof(area));
	for (i = 1; i <= M; i++)
	{
		if (shark[i].alive)
			area[shark[i].r][shark[i].c] = i;
	}
}

int main()
{
	int i;
	int answer = 0;
	t_shark tmp;

	cin >> R >> C >> M;
	memset(&tmp, 0, sizeof(tmp));
	shark.resize(M + 1, tmp);
	for (i = 1; i <= M; i++)
	{
		cin >> shark[i].r >> shark[i].c >> shark[i].s >> shark[i].d >> shark[i].z;
		if (shark[i].d == UP || shark[i].d == DOWN)
			shark[i].s %= (R - 1) * 2;
		else
			shark[i].s %= (C - 1) * 2;
		shark[i].alive = 1;
		area[shark[i].r][shark[i].c] = i;
	}
	for (i = 1; i <= C; i++)
	{
		answer += fishing(i);
		moving();
	}
	cout << answer << endl;
	return 0;
}