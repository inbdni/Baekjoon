#include <iostream>
#include <cstring>

using namespace std;

int N;
int M;
int dots[50][50];
bool visited[50][50];
int d[] = {1, -1, 0, 0};
bool answer;

bool is_alpha(int n)
{
	if (n < 'A' || n > 'Z')
		return false;
	return true;
}

void dfs(int init_x, int init_y, int x, int y, int dir, int side)
{
	int i;
	int dx;
	int dy;

	for (i = 0; i < 4; i++)
	{
		dx = x + d[i];
		dy = y + d[3 - i];
		if (dx >= 0 && dx < M && dy >= 0 && dy < N)
		{
			if (visited[dy][dx])
			{
				if (dx == init_x && dy == init_y && side >= 4)
				{
					answer = true;
					return ;
				}
			}
			else
			{
				if (dots[dy][dx] == dots[y][x])
				{
					visited[dy][dx] = true;
					if (i == dir)
						dfs(init_x, init_y, dx, dy, dir, side);
					else
						dfs(init_x, init_y, dx, dy, dir, side + 1);
				}
			}
		}
	}
}

int main()
{
	int i;
	int j;
	int k;
	string s;

	cin >> N >> M;
	if (N < 2 || N > 50 || M < 2 || M > 50)
		return -1;
	for (i = 0; i < N; i++)
	{
		cin >> s;
		for (j = 0; j < M; j++)
			dots[i][j] = s[j];
		s.clear();
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			for (k = 0; k < 4; k++)
			{
				memset(visited, false, sizeof(visited));
				visited[i][j] = true;
				dfs(j, i, j, i, k, 1);
				if (answer)
					break;
			}
		}
	}
	if (answer)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}