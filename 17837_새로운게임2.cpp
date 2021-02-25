#include <iostream>
#include <vector>
#include <algorithm>

#define	W	0
#define R	1
#define B	2

#define RIGHT	1
#define LEFT	2
#define UP		3
#define DOWN	4

using namespace std;

typedef struct s_piece
{
	int r;
	int c;
	int dir;
} t_piece;

int N;
int K;
int d[] = {0, 1, -1, 0, 0};
int board[13][13];
t_piece piece[11];
vector<int> state[13][13];

bool in_range(int dr, int dc)
{
	if (dr < 1 || dr > N || dc < 1 || dc > N)
		return false;
	return true;
}

void change_dir(t_piece *p)
{
	if (p->dir == RIGHT || p->dir == UP)
		p->dir += 1;
	else
		p->dir -= 1;
}

bool to_blue(int k)
{
	int dr, dc;
	t_piece *p;

	p = &piece[k];
	change_dir(p);
	dr = p->r + d[5 - p->dir];
	dc = p->c + d[p->dir];
	if (!in_range(dr, dc) || board[dr][dc] == B)
		return false;
	return true;
}

void to_red(int k, int idx, int dr, int dc)
{
	int i, r, c;
	t_piece *p;

	r = piece[k].r;
	c = piece[k].c;
	for (i = state[r][c].size() - 1; i >= idx; i--)
	{
		p = &piece[state[r][c][i]];
		p->r = dr;
		p->c = dc;
		state[dr][dc].push_back(state[r][c][i]);
	}
	state[r][c].erase(state[r][c].begin() + idx, state[r][c].end());
}

void to_white(int k, int idx, int dr, int dc)
{
	int i, r, c;
	t_piece *p;

	r = piece[k].r;
	c = piece[k].c;
	for (i = idx; i < state[r][c].size(); i++)
	{
		p = &piece[state[r][c][i]];
		p->r = dr;
		p->c = dc;
		state[dr][dc].push_back(state[r][c][i]);
	}
	state[r][c].erase(state[r][c].begin() + idx, state[r][c].end());
}

int turn()
{
	int t, k, idx;
	int dr, dc;
	t_piece *p;

	for (t = 1; t <= 1000; t++)
	{
		for (k = 1; k <= K; k++)
		{
			p = &piece[k];
			idx = find(state[p->r][p->c].begin(), state[p->r][p->c].end(), k) - state[p->r][p->c].begin();
			dr = p->r + d[5 - p->dir];
			dc = p->c + d[p->dir];
			if (!in_range(dr, dc) || board[dr][dc] == B)
			{
				if (!to_blue(k))
				{
					continue;
				}
				dr = p->r + d[5 - p->dir];
				dc = p->c + d[p->dir];
			}
			if (board[dr][dc] == R)
				to_red(k, idx, dr, dc);
			if (board[dr][dc] == W)
				to_white(k, idx, dr, dc);
			if (state[dr][dc].size() >= 4)
				return t;
		}
	}
	return -1;
}

int main()
{
	int i, j;
	int r, c, dir;

	cin >> N >> K;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			cin >> board[i][j];
		}
	}
	for (i = 1; i <= K; i++)
	{
		cin >> r >> c >> dir;
		piece[i].r = r;
		piece[i].c = c;
		piece[i].dir = dir;
		state[r][c].push_back(i);
	}
	cout << turn() << endl;
	return 0;
}