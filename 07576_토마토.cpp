#include <iostream>
#include <queue>

using namespace std;

int N;
int M;
int box[1001][1001];
int number;

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
		if (r < 0 || r >= N || c < 0 || c >= M)
			return false;
		return true;
	}
};

int bfs(queue<pos> &q)
{
	pos curr, next;
	int i, j, size;
	int day = 0;
	int d[] = {-1, 1, 0, 0};

	while (number && !q.empty())
	{
		day++;
		size = q.size();
		for (i = 0; i < size; i++)
		{
			curr = q.front();
			q.pop();
			for (j = 0; j < 4; j++)
			{
				next.init(curr.r + d[j], curr.c + d[3 - j]);
				if (!next.in_range())
					continue;
				if (box[next.r][next.c] != 0)
					continue;
				box[next.r][next.c] = 1;
				q.push(next);
				number--;
			}
		}
	}
	if (!number)
		return day;
	return -1;
}

int main() 
{
	int i, j;
	pos p;
	queue<pos> q;

	cin >> M >> N;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			cin >> box[i][j];
			if (box[i][j] == 0)
			{
				number++;
			}	
			else if (box[i][j] == 1)
			{
				p.init(i, j);
				q.push(p);
			}
		}
	}
	cout << bfs(q) << endl;
	return 0;
}