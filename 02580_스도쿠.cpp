#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
bool check_r[9][10];
bool check_c[9][10];
bool check_box[9][10];
bool done;

void set_flag(int r, int c, int i, bool flag)
{
	if (flag)
		board[r][c] = i;
	else
		board[r][c] = 0;
	check_r[r][i] = flag;
	check_c[c][i] = flag;
	check_box[r / 3 * 3 + c / 3][i] = flag;
}

void print()
{
	int i, j;

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void dfs(int num)
{
	int r, c, i;

	if (done)
		return;
	r = num / 9;
	c = num % 9;
	if (num == 81)
	{
		done = true;
		print();
		return;
	}
	if (!board[r][c])
	{
		for (i = 1; i <= 9; i++)
		{
			if (!check_r[r][i] && !check_c[c][i] && !check_box[r / 3 * 3 + c / 3][i])
			{
				set_flag(r, c, i, true);
				dfs(num + 1);
				set_flag(r, c, i, false);
			}
		}
	}
	else
	{
		dfs(num + 1);
	}
}

int main()
{
	int i, j, num;

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			cin >> num;
			board[i][j] = num;
			check_r[i][num] = true;
			check_c[j][num] = true;
			check_box[i / 3 * 3 + j / 3][num] = true;
		}
	}
	dfs(0);
	return 0;
}