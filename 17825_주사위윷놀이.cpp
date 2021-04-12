#include <iostream>
#include <vector>

using namespace std;

struct pos
{
	int r;
	int c;
	bool finish;

	void init(int r, int c, bool finish)
	{
		this->r = r;
		this->c = c;
		this->finish = finish;
	}
};

vector< vector<int> > board;
vector<int> turn;
int max_score;

void init_board()
{
	int i;
	int line10[] = {13, 16, 19};
	int line20[] = {22, 24};
	int line30[] = {28, 27, 26};
	int line25[] = {25, 30, 35};

	board.resize(5);
	for (i = 0; i < 21; i++)
		board[0].push_back(i * 2);
	board[0].push_back(0);
	for (i = 0; i < 3; i++)
		board[1].push_back(line10[i]);
	for (i = 0; i < 2; i++)
		board[2].push_back(line20[i]);
	for (i = 0; i < 3; i++)
		board[3].push_back(line30[i]);
	for (i = 0; i < 3; i++)
		board[4].push_back(line25[i]);
}

pos move(int cnt, pos curr)
{
	int i;
	pos next = curr;

	if (next.c == 5 || next.c == 10 || next.c == 15)
	{
		next.r = next.c / 5;
		next.c = 0;
		cnt--;
	}
	for (i = 0; i < cnt; i++)
	{
		if (++next.c == board[next.r].size())
		{
			if (next.r == 0)
			{
				next.finish = true;
				return next;
			}
			else if (next.r > 0 && next.r < 4)
			{
				next.r = 4;
				next.c = 0;
			}
			else
			{
				next.r = 0;
				next.c = 20;
			}
		}
	}
	return next;
}

bool exist(int num, vector<pos> &piece)
{
	int i;

	if (piece[num].finish)
		return false;
	for (i = 0; i < 4; i++)
	{
		if (i == num || piece[i].finish)
			continue;
		if (piece[i].r == piece[num].r && piece[i].c == piece[num].c)
			return true;
	}
	return false;
}

void dfs(int t, int total_score, vector<pos> piece)
{
	int i, score;
	pos curr, next;
	vector<pos> new_piece;

	if (t == 10)
	{
		max_score = max(max_score, total_score);
		return;
	}
	for (i = 0; i < 4; i++)
	{
		if (piece[i].finish)
			continue;
		new_piece.assign(piece.begin(), piece.end());
		new_piece[i] = move(turn[t], new_piece[i]);
		if (exist(i, new_piece))
			continue;
		score = board[new_piece[i].r][new_piece[i].c];
		dfs(t + 1, total_score + score, new_piece);
	}
}

int main()
{
	int i, num;
	pos p;
	vector<pos> piece;

	for (i = 0; i < 10; i++)
	{
		cin >> num;
		turn.push_back(num);
	}
	init_board();
	p.init(0, 0, false);
	for (i = 0; i < 4; i++)
	{
		piece.push_back(p);
	}
	dfs(0, 0, piece);
	cout << max_score << endl;
	return 0;
}
