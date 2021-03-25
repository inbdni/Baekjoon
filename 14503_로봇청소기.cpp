#include <iostream>

#define	NORTH	0
#define	EAST	1
#define	SOUTH	2
#define	WEST	3

using namespace std;

struct pos
{
	int r;
	int c;
	int d;
};

int N;
int M;
bool board[50][50];
bool visit[50][50];
pos robot;

int clean()
{
	int i, res = 0;
	int nr, nc, dir;
	int dr[] = {-1, 0, 1, 0};
	int dc[] = {0, 1, 0, -1};
	bool flag;

	visit[robot.r][robot.c] = true;
	res++;
	while (1)
	{
		flag = false;
		for (i = 1; i <= 4; i++)
		{
			dir = robot.d - i;
			if (dir < 0)
				dir += 4;
			nr = robot.r + dr[dir];
			nc = robot.c + dc[dir];
			if (!board[nr][nc] && !visit[nr][nc])
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			robot.r = nr;
			robot.c = nc;
			robot.d = dir;
			visit[robot.r][robot.c] = true;
			res++;
		}
		else
		{
			robot.r -= dr[robot.d];
			robot.c -= dc[robot.d];
			if (board[robot.r][robot.c])
				return res;
		}
	}
}

int main()
{
	int i, j;

	cin >> N >> M;
	cin >> robot.r >> robot.c >> robot.d;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			cin >> board[i][j];
	}
	cout << clean() << endl;
	return 0;
}