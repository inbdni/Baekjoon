#include <iostream>

using namespace std;

int N;
int M;
bool board[21][21];
int dn[] = {-1, 1, 0, 0};
int dm[] = {0, 0, -1, 1};
int answer = 11;

bool is_on(int y, int x)
{
	if (y < 1 || y > N || x < 1 || x > M)
		return false;
	return true;
}

void dfs(int cnt, int y1, int x1, int y2, int x2)
{
	int i;
	int dy1, dx1, dy2, dx2;

	if (cnt > 10)
		return;
	if (is_on(y1, x1) != is_on(y2, x2))
	{
		answer = min(answer, cnt);
		return;
	}
	for (i = 0; i < 4; i++)
	{
		dy1 = y1 + dn[i];
		dx1 = x1 + dm[i];
		dy2 = y2 + dn[i];
		dx2 = x2 + dm[i];
		if (!(is_on(dy1, dx1) || is_on(dy2, dx2)))
			continue;
		if (is_on(dy1, dx1) && board[dy1][dx1])
		{
			dy1 = y1;
			dx1 = x1;
		}
		if (is_on(dy2, dx2) && board[dy2][dx2])
		{
			dy2 = y2;
			dx2 = x2;
		}
		dfs(cnt + 1, dy1, dx1, dy2, dx2);
	}
}

int main()
{
	int i, j, k = 0;
	int c[2][2];
	string s;

	cin >> N >> M;
	for (i = 1; i <= N; i++)
	{
		cin >> s;
		for (j = 0; j < M; j++)
		{
			if (s[j] == '#')
			{
				board[i][j + 1] = 1;
				continue;
			}
			if (s[j] == 'o')
			{
				c[k][0] = i;
				c[k][1] = j + 1;
				k++;
			}
			board[i][j + 1] = 0;	
		}
		s.clear();
	}
	dfs(0, c[0][0], c[0][1], c[1][0], c[1][1]);
	if (answer > 10)
		answer = -1;
	cout << answer << endl;
	return 0;
}