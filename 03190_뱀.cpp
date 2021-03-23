#include <iostream>
#include <deque>

#define	U	0
#define	R	1
#define	D	2
#define L	3

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
int K;
int board[101][101];
deque< pair<int, char> > turn;

int get_dir(int curr, char next)
{
	int res;

	if (next == 'L')
		res = curr - 1;
	else
		res = curr + 1;
	if (res < 0)	
		res = 3;
	if (res > 3)	
		res = 0;
	return res;
}

bool is_end(pos p, deque<pos> &snake)
{
	int i;

	if (p.r < 1 || p.r > N || p.c < 1 || p.c > N)
		return true;
	for (i = 0; i < snake.size(); i++)
	{
		if (snake[i].r == p.r && snake[i].c == p.c)
			return true;
	}
	return false;
}

int game()
{
	deque<pos> snake;
	pos curr, next;
	int dr[] = {-1, 0, 1, 0};
	int dc[] = {0, 1, 0, -1};
	int dir = R;
	int time = 0;

	curr.init(1, 1);
	snake.push_back(curr);
	while(1)
	{
		time++;
		curr = snake.front();
		next.init(curr.r + dr[dir], curr.c + dc[dir]);
 		if (is_end(next, snake))
		{
			break;
		}
		snake.push_front(next);
		if (board[next.r][next.c])
		{
			board[next.r][next.c] = 0;
		}
		else
		{
			snake.pop_back();
		}
		if (time == turn.front().first)
		{
			dir = get_dir(dir, turn.front().second);
			turn.pop_front();
		}
	}
	return time;
}

int main()
{
	int i, r, c, t;
	char dir;

	cin >> N >> K;
	for (i = 0; i < K; i++)
	{
		cin >> r >> c;
		board[r][c] = 1;
	}
	cin >> K;
	for (i = 0; i < K; i++)
	{
		cin >> t >> dir;
		turn.push_back(make_pair(t, dir));
	}
	cout << game() << endl;
	return 0;
}