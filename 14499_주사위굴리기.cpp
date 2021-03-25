#include <iostream>

#define EAST	1
#define	WEST	2
#define	NORTH	3
#define	SOUTH	4

#define TOP		0
#define BOTTOM	5
#define LEFT	3
#define RIGHT	2
#define FRONT	4
#define BACK	1

using namespace std;

int N;
int M;
int K;
int pos[2];
int dice[6];
int map[20][20];

bool move(int dir)
{
	int dr[] = {0, 0, 0, -1, 1};
	int dc[] = {0, 1, -1, 0, 0};

	pos[0] += dr[dir];
	pos[1] += dc[dir];
	if (pos[0] >= 0 && pos[0] < N && pos[1] >= 0 && pos[1] < M)
		return true;
	pos[0] -= dr[dir];
	pos[1] -= dc[dir];
	return false;
}

void roll(int dir)
{
	int i, tmp;
	int hor[] = {TOP, LEFT, BOTTOM, RIGHT};
	int ver[] = {TOP, BACK, BOTTOM, FRONT};

	if (dir == EAST)
	{
		tmp = dice[hor[0]];
		for (i = 0; i < 3; i++)
			dice[hor[i]] = dice[hor[i + 1]];
		dice[hor[i]] = tmp;
	}
	else if (dir == WEST)
	{
		tmp = dice[hor[3]];
		for (i = 3; i > 0; i--)
			dice[hor[i]] = dice[hor[i - 1]];
		dice[hor[i]] = tmp;
	}
	else if (dir == NORTH)
	{
		tmp = dice[ver[3]];
		for (i = 3; i > 0; i--)
			dice[ver[i]] = dice[ver[i - 1]];
		dice[ver[i]] = tmp;
	}
	else
	{
		tmp = dice[ver[0]];
		for (i = 0; i < 3; i++)
			dice[ver[i]] = dice[ver[i + 1]];
		dice[ver[i]] = tmp;
	}
}

void turn(int dir)
{
	if (!move(dir))
		return;
	roll(dir);
	if (map[pos[0]][pos[1]])
	{
		dice[BOTTOM] = map[pos[0]][pos[1]];
		map[pos[0]][pos[1]] = 0;
	}
	else
	{
		map[pos[0]][pos[1]] = dice[BOTTOM];
	}
	cout << dice[TOP] << endl;
}

int main()
{
	int i, j, k, dir;

	cin >> N >> M >> pos[0] >> pos[1] >> K;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			cin >> map[i][j];
	}
	for (k = 0; k < K; k++)
	{
		cin >> dir;
		turn(dir);
	}
	return 0;
}