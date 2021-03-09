#include <iostream>
#include <string>
#include <vector>
#include <queue>

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
vector< vector<int> > board;
vector<int> line;

bool bfs()
{
	queue<pos> q;
	pos curr, next;
	int dr[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
	int dc[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
	int i, j, size;

	next.init(7, 0);
	q.push(next);
	while (!q.empty())
	{
		size = q.size();
		for (i = 0; i < size; i++)
		{
			curr = q.front();
			q.pop();
			if (curr.r == 0 && curr.c == 7)
			{
				return true;
			}
			if (board[curr.r][curr.c])
			{
				continue;
			}
			for (j = 0; j < 9; j++)
			{
				next.init(curr.r + dr[j], curr.c + dc[j]);
				if (next.r < 0 || next.r >= N || next.c < 0 || next.c >= N)
					continue;
				if (board[next.r][next.c])
					continue;
				q.push(next);
			}
		}
		board.insert(board.begin(), line);
		board.pop_back();
	}
	return false;
}

int main()
{
	int i, j;
	string s;

	N = 8;
	for (i = 0; i < N; i++)
	{
		cin >> s;
		for (j = 0; j < N; j++)
		{
			if (s[j] == '.')
				line.push_back(0);
			else
				line.push_back(1);
		}
		board.push_back(line);
		line.clear();
	}
	line.resize(8, 0);
	cout << bfs() << endl;
	return 0;
}
