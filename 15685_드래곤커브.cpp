#include <iostream>
#include <vector>

#define	R	0
#define	U	1
#define	L	2
#define	D	3

using namespace std;

int N;
bool board[101][101];
vector<int> draw[11];	

void init()
{
	int prev_gen, curr_gen;
	int curr_dir, next_dir;
	int idx;

	draw[0].push_back(R);
	for (curr_gen = 1; curr_gen <= 10; curr_gen++)
	{
		for (prev_gen = curr_gen - 1; prev_gen >= 0; prev_gen--)
		{
			for (idx = draw[prev_gen].size() - 1; idx >= 0; idx--)
			{
				curr_dir= draw[prev_gen][idx];
				next_dir = curr_dir + 1;
				if (next_dir == 4)
					next_dir = 0;
				draw[curr_gen].push_back(next_dir);
			}
		}
	}
}

void drawing(int x, int y, int d, int g)
{
	int i, j, dir;
	int nx, ny;
	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, -1, 0, 1};

	nx = x;
	ny = y;
	board[ny][nx] = true;
	for (i = 0; i <= g; i++)
	{
		for (j = 0; j < draw[i].size(); j++)
		{
			dir = draw[i][j] + d;
			if (dir >= 4)
				dir -= 4;
			nx += dx[dir];
			ny += dy[dir];
			board[ny][nx] = true;
		}
	}
}

int count_rec()
{
	int x, y;
	int res = 0;

	for (x = 0; x < 100; x++)
	{
		for (y = 0; y < 100; y++)
		{
			if (board[x][y] && board[x + 1][y] && board[x][y + 1] && board[x + 1][y + 1])
				res++;
		}
	}
	return res;
}

int main()
{
	int x, y, d, g;

	cin >> N;
	init();
	while (N--)
	{
		cin >> x >> y >> d >> g;
		drawing(x, y, d, g);
	}
	cout << count_rec() << endl;
	return 0;
}