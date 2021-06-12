#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int M;
int D;

struct pos
{
	int r;
	int c;

	void init(int r, int c)
	{
		this->r = r;
		this->c = c;
	}

	bool in_range()
	{
		if (r < 0 || c < 0 || c >= M)
			return false;
		return true;
	}
};

struct cmp
{
	bool operator()(pos a, pos b)
	{
		return a.c > b.c;
	}
};

void init(vector<vector<int> > &board, vector<bool> &archer)
{
	int i, j;

	board.resize(N, vector<int>(M));
	for (i = 0; i < board.size(); i++)
	{
		for (j = 0; j < board[0].size(); j++)
		{
			cin >> board[i][j];
		}
	}
	for (i = 0; i < M - 3; i++)
	{
		archer.push_back(false);
	}
	for (i = M - 3; i < M; i++)
	{
		archer.push_back(true);
	}
}

void find_target(vector<vector<int> > &board, queue<pos> &target, int archer)
{
	queue<pos> q;
	priority_queue<pos, vector<pos>, cmp> cand;
	vector<vector<bool> > visit;
	pos curr, next;
	int dr[] = {0, -1, 0};
	int dc[] = {-1, 0, 1};
	int i, s, size, d = 1;

	visit.resize(N, vector<bool>(M, false));
	curr.init(board.size() - 1, archer);
	if (board[curr.r][curr.c])
	{
		target.push(curr);
		return;
	}
	q.push(curr);
	visit[curr.r][curr.c] = true;
	while (!q.empty() && d++ < D)
	{
		size = q.size();
		for (s = 0; s < size; s++)
		{
			curr = q.front();
			q.pop();
			for (i = 0; i < 3; i++)
			{
				next.init(curr.r + dr[i], curr.c + dc[i]);
				if (!next.in_range())
					continue;
				if (visit[next.r][next.c])
					continue;
				if (board[next.r][next.c])
					cand.push(next);
				q.push(next);
				visit[next.r][next.c] = true;
			}
		}
		if (!cand.empty())
		{
			target.push(cand.top());
			return;
		}
	}
}

int game(vector<vector<int> > board, vector<bool> archer)
{
	queue<pos> target;
	pos p;
	int i, cnt = 0;

	while (!board.empty())
	{
		for (i = 0; i < archer.size(); i++)
		{
			if (archer[i])
				find_target(board, target, i);
		}
		while (!target.empty())
		{
			p = target.front();
			target.pop();
			if (board[p.r][p.c])
			{
				board[p.r][p.c] = false;
				cnt++;
			}
		}
		board.pop_back();
	}
	return cnt;
}

int main()
{
	vector<vector<int> > board;
	vector<bool> archer;
	int answer = 0;

	cin >> N >> M >> D;
	init(board, archer);
	do
	{
		answer = max(answer, game(board, archer));
	} while (next_permutation(archer.begin(), archer.end()));
	cout << answer << endl;
	return 0;
}