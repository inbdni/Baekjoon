#include <iostream>
#include <string>
#include <queue>

#define	NORTH	0
#define	EAST	1
#define	SOUTH	2
#define	WEST	3

using namespace std;

struct pos
{
	int r;
	int c;
	int dir;
};

int N;
int M;
pos robot;

void turn(int d)
{
	if (d)
	{
		robot.dir++;
		if (robot.dir > 3)
			robot.dir = 0;
	}
	else
	{
		robot.dir--;
		if (robot.dir < 0)
			robot.dir = 3;
	}
}

void move(int d)
{
	int dr[] = {1, 0, -1, 0};
	int dc[] = {0, 1, 0, -1};

	robot.r += dr[robot.dir] * d;
	robot.c += dc[robot.dir] * d;
}

bool in_range()
{
	if (robot.r < 0 || robot.r > M || robot.c < 0 || robot.c > M)
		return false;
	return true;
}

int main()
{
	int i, d;
	string s;
	bool flag = false;
	queue< pair<string, int> > cmd;

	cin >> M >> N;
	robot.r = 0;
	robot.c = 0;
	robot.dir = EAST;
	for (i = 0; i < N; i++)
	{
		cin >> s >> d;
		cmd.push(make_pair(s, d));
	}
	while (!cmd.empty())
	{
		s = cmd.front().first;
		d = cmd.front().second;
		cmd.pop();
		if (s[0] == 'T')
		{
			turn(d);
			continue;
		}
		move(d);
		if (!in_range())
		{
			flag = true;
			break;
		}
	}
	if (flag)
		cout << -1 << endl;
	else
		cout << robot.c << " " << robot.r << endl;
	return 0;
}