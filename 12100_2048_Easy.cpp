#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int max_block;

void get_max(vector< vector<int> > &board)
{
	int i, j;

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			max_block = max(max_block, board[i][j]);
		}
	}
}

vector< vector<int> > move_up(vector< vector<int> > &board)
{
	vector< vector<int> > res;
	queue<int> q;
	int r, c, idx, block;

	res.resize(N + 1, vector<int> (N + 1, 0));
	for (c = 1; c <= N; c++)
	{
		for (r = 1; r <= N; r++)
		{
			if (board[r][c])
				q.push(board[r][c]);
		}
		idx = 1;
		while (!q.empty())
		{
			block = q.front();
			q.pop();
			if (res[idx][c] == 0)
				res[idx][c] = block;
			else if (res[idx][c] == block)
				res[idx++][c] += block;
			else
				res[++idx][c] = block;
		}
	}
	return res;
}

vector< vector<int> > move_down(vector< vector<int> > &board)
{
	vector< vector<int> > res;
	queue<int> q;
	int r, c, idx, block;

	res.resize(N + 1, vector<int> (N + 1, 0));
	for (c = 1; c <= N; c++)
	{
		for (r = N; r >= 1; r--)
		{
			if (board[r][c])
				q.push(board[r][c]);
		}
		idx = N;
		while (!q.empty())
		{
			block = q.front();
			q.pop();
			if (res[idx][c] == 0)
				res[idx][c] = block;
			else if (res[idx][c] == block)
				res[idx--][c] += block;
			else
				res[--idx][c] = block;
		}
	}
	return res;
}

vector< vector<int> > move_left(vector< vector<int> > &board)
{
	vector< vector<int> > res;
	queue<int> q;
	int r, c, idx, block;

	res.resize(N + 1, vector<int> (N + 1, 0));
	for (r = 1; r <= N; r++)
	{
		for (c = 1; c <= N; c++)
		{
			if (board[r][c])
				q.push(board[r][c]);
		}
		idx = 1;
		while (!q.empty())
		{
			block = q.front();
			q.pop();
			if (res[r][idx] == 0)
				res[r][idx] = block;
			else if (res[r][idx] == block)
				res[r][idx++] += block;
			else
				res[r][++idx] = block;
		}
	}
	return res;
}

vector< vector<int> > move_right(vector< vector<int> > &board)
{
	vector< vector<int> > res;
	queue<int> q;
	int r, c, idx, block;

	res.resize(N + 1, vector<int> (N + 1, 0));
	for (r = 1; r <= N; r++)
	{
		for (c = N; c >= 1; c--)
		{
			if (board[r][c])
				q.push(board[r][c]);
		}
		idx = N;
		while (!q.empty())
		{
			block = q.front();
			q.pop();
			if (res[r][idx] == 0)
				res[r][idx] = block;
			else if (res[r][idx] == block)
				res[r][idx--] += block;
			else
				res[r][--idx] = block;
		}
	}
	return res;
}

void dfs(int depth, vector< vector<int> > board)
{
	if (depth == 5)
	{
		get_max(board);
		return;
	}
	dfs(depth + 1, move_up(board));
	dfs(depth + 1, move_down(board));
	dfs(depth + 1, move_left(board));
	dfs(depth + 1, move_right(board));
}

int main()
{
	int i, j;
	vector< vector<int> > board;

	cin >> N;
	board.resize(N + 1, vector<int> (N + 1, 0));
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			cin >> board[i][j];
		}
	}
	dfs(0, board);
	cout << max_block << endl;
	return 0;
}