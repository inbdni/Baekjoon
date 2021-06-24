#include <iostream>
#include <vector>
#include <queue>

#define	WEST	0
#define	NORTH	1
#define	EAST	2
#define	SOUTH	3

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
bool map[51][51][4];
int room[51][51];
int num;
int max_size;
vector<int> room_size;
vector< vector<bool> > adjacent_room;

void check_wall(int r, int c, int wall)
{
	if (wall & 0x01)
		map[r][c][WEST] = true;
	if (wall & 0x02)
		map[r][c][NORTH] = true;
	if (wall & 0x04)
		map[r][c][EAST] = true;
	if (wall & 0x08)
		map[r][c][SOUTH] = true;
}

bool in_range(pos p)
{
	if (p.r < 0 || p.r >= M || p.c < 0 || p.c >= N)
		return false;
	return true;
}

void bfs(int r, int c)
{
	queue<pos> q;
	pos curr, next;
	int dr[] = {0, -1, 0, 1};
	int dc[] = {-1, 0, 1, 0};
	int i, cnt = 0;

	curr.init(r, c);
	q.push(curr);
	room[r][c] = ++num;
	adjacent_room.push_back(vector<bool> (num, false));
	while (!q.empty())
	{
		cnt++;
		curr = q.front();
		q.pop();
		for (i = 0; i < 4; i++)
		{
			next.init(curr.r + dr[i], curr.c + dc[i]);
			if (!in_range(next))
				continue;
			if (map[curr.r][curr.c][i])
			{
				if (room[next.r][next.c] && room[next.r][next.c] != num)
					adjacent_room[num][room[next.r][next.c]] = true;
				continue;
			}
			if (room[next.r][next.c])
				continue;
			q.push(next);
			room[next.r][next.c] = num;
		}
	}
	room_size.push_back(cnt);
	max_size = max(max_size, cnt);
}

void find_room()
{
	int i, j;

	room_size.resize(1);
	adjacent_room.resize(1);
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (!room[i][j])
				bfs(i, j);
		}
	}
}

int destroy_wall()
{
	int i, j, sum, res = 0;

	for (i = 1; i <= num; i++)
	{
		for (j = 1; j < adjacent_room[i].size(); j++)
		{
			if (adjacent_room[i][j])
				res = max(res, room_size[i] + room_size[j]);
		}
	}
	return res;
}

int main()
{
	int i, j, k, wall;

	cin >> N >> M;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> wall;
			check_wall(i, j, wall);
		}
	}
	find_room();
	cout << num << endl;
	cout << max_size << endl;
	cout << destroy_wall() << endl;
	return 0;
}