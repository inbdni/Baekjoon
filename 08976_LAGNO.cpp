#include <iostream>
#include <string>

using namespace std;

string board[8];
int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool in_range(int nr, int nc)
{
	if (nr < 0 || nr >= 8 || nc < 0 || nc >= 8)
		return false;
	return true;
}

int get_number(int nr, int nc, int dir)
{
	int number = 0;
	bool flag = true;

	while (board[nr][nc] == 'W')
	{
		number++;
		nr += dr[dir];
		nc += dc[dir];
		if (!in_range(nr, nc))
		{
			flag = false;
			break;
		}
	}
	if (flag && board[nr][nc] == 'B')
	{
		return number;
	}
	return 0;
}

int main()
{
	int i, j, k;
	int nr, nc;
	int res, answer = 0;

	for (i = 0; i < 8; i++)
	{
		cin >> board[i];
	}
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (board[i][j] != '.')
			{
				continue;
			}
			res = 0;
			for (k = 0; k < 8; k++)
			{
				nr = i + dr[k];
				nc = j + dc[k];
				if (!in_range(nr, nc))
					continue;
				if (board[nr][nc] != 'W')
					continue;
				res += get_number(nr, nc, k);
			}
			answer = max(answer, res);
		}
	}
	cout << answer << endl;
	return 0;
}