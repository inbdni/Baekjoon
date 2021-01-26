#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int M;
int K;
int A[11][11];
int nourish[11][11];
vector<int> tree[11][11];

void ss()
{
	int r, c, t;
	
	for (r = 1; r <= N; r++)
	{
		for (c = 1; c <= N; c++)
		{
			// spring
			for (t = 0; t < tree[r][c].size(); t++)
			{
				if (nourish[r][c] < tree[r][c][t])
					break;
				nourish[r][c] -= tree[r][c][t];
				tree[r][c][t]++;
			}
			// summer
			while (t < tree[r][c].size())
			{
				nourish[r][c] += tree[r][c][t] / 2;
				tree[r][c].erase(tree[r][c].begin() + t);
			}
		}
	}
}

void breeding(int r, int c, int t)
{
	int i, j;
	int dr, dc;
	int d[] = {-1, 0, 1};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			dr = r + d[i];
			dc = c + d[j];
			if (dr == r && dc == c)
				continue;
			if (dr > 0 && dr <= N && dc > 0 && dc <= N)
			{
				tree[dr][dc].insert(tree[dr][dc].begin(), 1);
			}
		}
	}
}

void fw()
{
	int r, c, t;
	int i, j;
	
	for (r = 1; r <= N; r++)
	{
		for (c = 1; c <= N; c++)
		{
			// fall
			for (t = 0; t < tree[r][c].size(); t++)
			{
				if (tree[r][c][t] % 5 == 0)
				{
					breeding(r, c, t);
				}
			}
			// winter
			nourish[r][c] += A[r][c];
		}
	}
}

int main()
{
	int r, c;
	int x, y, z;
	int answer = 0;

	cin >> N >> M >> K;
	for (r = 1; r <= N; r++)
	{
		for (c = 1; c <= N; c++)
		{
			cin >> A[r][c];
			nourish[r][c] = 5;
		}
	}
	for (r = 1; r <= M; r++)
	{
		cin >> x >> y >> z;
		tree[x][y].push_back(z);
		sort(tree[x][y].begin(), tree[x][y].end());
	}
	for (r = 1; r <= K; r++)
	{
		ss();
		fw();
	}
	for (r = 1; r <= N; r++)
	{
		for (c = 1; c <= N; c++)
		{
			answer += tree[r][c].size();
		}
	}
	cout << answer << endl;
	return 0;
}