#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;
int M;
int lab[9][9];
bool checked[9][9];
int d[] = {-1, 1, 0, 0};
int answer;

int birus()
{
	queue< pair<int, int> > q;
	int i, j, k;
	int r, c, nr, nc;
	int res = 0;

	memset(checked, false, sizeof(checked));
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			if (lab[i][j] == 2)
			{
				q.push(make_pair(i, j));
				checked[i][j] = true;
			}
		}
	}
	while (!q.empty())
	{
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (k = 0; k < 4; k++)
		{
			nr = r + d[k];
			nc = c + d[3 - k];
			if (nr > 0 && nr <= N && nc > 0 && nc <= M)
			{
				if (lab[nr][nc] == 0 && !checked[nr][nc])
				{
					q.push(make_pair(nr, nc));
					checked[nr][nc] = true;
				}
			}
		}
	}
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			if (lab[i][j] == 0 && !checked[i][j])
			{
				res++;
			}
		}
	}
	return res;
}

void wall(int depth)
{
	int i, j;

	if (depth == 3)
	{
		answer = max(answer, birus());
		return;
	}
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			if (lab[i][j] == 0)
			{
				lab[i][j] = 1;
				wall(depth + 1);
				lab[i][j] = 0;			
			}
		}
	}
}

int main()
{
	int i, j;

	cin >> N >> M;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			cin >> lab[i][j];
		}
	}
	wall(0);
	cout << answer << endl;
	return 0;
}