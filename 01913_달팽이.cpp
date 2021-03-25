#include <iostream>

using namespace std;

int N;
int target;
int board[1000][1000];
int pos[2];

void make_board()
{
	int r, c, dir = 0;
	int l, limit = 1;
	int num = 1;
	int dr[] = {-1, 0, 1, 0};
	int dc[] = {0, 1, 0, -1};

	r = (N + 1) / 2;
	c = (N + 1) / 2;
	while (num <= N * N)
	{
		for (l = 0; l < limit; l++)
		{
			board[r][c] = num++;
			r += dr[dir];
			c += dc[dir];
			if (num == target)
			{
				pos[0] = r;
				pos[1] = c;
			}
		}
		if (++dir == 4)
			dir = 0;
		if (dir % 2 == 0)
			limit++;
	}
}

void print_board()
{
	int i, j;

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
	cout << pos[0] << " " << pos[1] << endl;
}

int main()
{
	cin >> N >> target;
	make_board();
	print_board();
	return 0;
}