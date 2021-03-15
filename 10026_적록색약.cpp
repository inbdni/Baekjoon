#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N;
char grid[101][101];
int normal[101][101];
int blindness[101][101];

void bfs1(int r, int c, int cnt)
{
	queue< pair<int, int> > q;
	pair<int, int> curr, next;
	int d[] = {-1, 1, 0, 0};
	int i;

	normal[r][c] = cnt;
	q.push(make_pair(r, c));
	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		for (i = 0; i < 4; i++)
		{
			next = make_pair(curr.first + d[i], curr.second + d[3 - i]);
			if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= N)
				continue;
			if (normal[next.first][next.second] != 0)
				continue;
			if (grid[next.first][next.second] != grid[r][c])
				continue;
			normal[next.first][next.second] = cnt;
			q.push(next);
		}
	}
}

void bfs2(int r, int c, int cnt)
{
	queue< pair<int, int> > q;
	pair<int, int> curr, next;
	int d[] = {-1, 1, 0, 0};
	int i;
	bool is_blue;

	if (grid[r][c] == 'B')
		is_blue = true;
	else
		is_blue = false;
	
	blindness[r][c] = cnt;
	q.push(make_pair(r, c));
	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		for (i = 0; i < 4; i++)
		{
			next = make_pair(curr.first + d[i], curr.second + d[3 - i]);
			if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= N)
				continue;
			if (blindness[next.first][next.second] != 0)
				continue;
			if (is_blue && grid[next.first][next.second] != 'B')
				continue;
			if (!is_blue && grid[next.first][next.second] == 'B')
				continue;
			blindness[next.first][next.second] = cnt;
			q.push(next);
		}
	}
}

int main()
{
	int i, j;
	int cnt1 = 0;
	int cnt2 = 0;
	string s;

	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> s;
		for (j = 0; j < N; j++)
		{
			grid[i][j] = s[j];
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (normal[i][j] == 0)
				bfs1(i, j, ++cnt1);
			if (blindness[i][j] == 0)
				bfs2(i, j, ++cnt2);
		}
	}
	cout << cnt1 << " " << cnt2 << endl;
	return 0;
}