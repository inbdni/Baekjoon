#include <iostream>
#include <string>
#include <deque>
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

int H;
int W;
string prison[102];
int door[102][102][3];
deque<pos> people;

void init()
{
	int i;

	for (i = 0; i <= H + 1; i++)
		prison[i].clear();
	memset(door, -1, sizeof(door));
	people.clear();
}

void input()
{
	int i, j;
	string s;
	pos p;

	cin >> H >> W;
	s.resize(W + 2, '.');
	prison[0] = s;
	prison[H + 1] = s;
	p.init(0, 0);
	people.push_back(p);
	for (i = 1; i <= H; i++)
	{
		cin >> s;
		prison[i] = '.' + s + '.';
		for (j = 1; j <= W; j++)
		{
			if (prison[i][j] == '$')
			{
				p.init(i, j);
				people.push_back(p);
			}	
		}
	}
}

bool in_range(pos p)
{
	if (p.r < 0 || p.r > H + 1 || p.c < 0 || p.c > W + 1)
		return false;
	return true;
}

void bfs(int k)
{
	deque<pos> dq;
	pos curr, next;
	int d[] = {-1, 1, 0, 0};
	int i;

	next = people[k];
	door[next.r][next.c][k] = 0;
	dq.push_back(next);
	while (!dq.empty())
	{
		curr = dq.front();
		dq.pop_front();
		for (i = 0; i < 4; i++)
		{
			next.init(curr.r + d[i], curr.c + d[3 - i]);
			if (!in_range(next))
				continue;
			if (prison[next.r][next.c] == '*')
				continue;
			if (door[next.r][next.c][k] != -1)
				continue;
			if (prison[next.r][next.c] == '#')
			{
				door[next.r][next.c][k] = door[curr.r][curr.c][k] + 1;
				dq.push_back(next);
			}
			else
			{
				door[next.r][next.c][k] = door[curr.r][curr.c][k];
				dq.push_front(next);
			}
			
		}
	}
}

int find_min()
{
	int i, j, k;
	int sum, res = INT_MAX;

	for (i = 0; i <= H + 1; i++)
	{
		for (j = 0; j <= W + 1; j++)
		{
			if (prison[i][j] == '*')
				continue;
			sum = 0;
			for (k = 0; k < 3; k++)
				sum += door[i][j][k];
			if (prison[i][j] == '#')
				sum -= 2;
			if (sum < 0)
				continue;
			res = min(res, sum);
		}
	}
	return res;
}

int main()
{
	int t, T;
	int k;

	cin >> T;
	for (t = 0; t < T; t++)
	{
		init();
		input();
		for (k = 0; k < 3; k++)
			bfs(k);
		cout << find_min() << endl;
	}
	return 0;
}
