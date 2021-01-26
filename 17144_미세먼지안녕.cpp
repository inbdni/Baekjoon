#include <iostream>
#include <cstring>

using namespace std;

int R;
int C;
int T;
int A[51][51];
int ap[2];

void spread_dust()
{
	int i, j, k;
	int dr, dc, cnt;
	int S[51][51];
	int d[] = {-1, 1, 0, 0};

	memset(S, 0, sizeof(S));
	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= C; j++)
		{
			if (A[i][j] == -1)
				continue;
			cnt = 0;
			for (k = 0; k < 4; k++)
			{
				dr = i + d[k];
				dc = j + d[3 - k];
				if (A[dr][dc] == -1)
					continue;
				if (dr > 0 && dr <= R && dc > 0 && dc <= C)
				{
					S[dr][dc] += A[i][j] / 5;
					cnt++;
				}
			}
			A[i][j] = A[i][j] - A[i][j] / 5 * cnt;
		}
	}
	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= C; j++)
		{
			A[i][j] += S[i][j];
		}
	}
}

void run_top()
{
	int i, j;

	for (i = ap[0] - 1; i > 1; i--)
	{
		A[i][1] = A[i - 1][1];
	}
	for (j = 1; j < C; j++)
	{
		A[1][j] = A[1][j + 1];
	}
	for (i = 1; i < ap[0]; i++)
	{
		A[i][C] = A[i + 1][C];
	}
	for (j = C; j > 2; j--)
	{
		A[ap[0]][j] = A[ap[0]][j - 1];
	}
	A[ap[0]][2] = 0;
}

void run_bottom()
{
	int i, j;

	for (i = ap[1] + 1; i < R; i++)
	{
		A[i][1] = A[i + 1][1];
	}
	for (j = 1; j < C; j++)
	{
		A[R][j] = A[R][j + 1];
	}
	for (i = R; i > ap[1]; i--)
	{
		A[i][C] = A[i - 1][C];
	}
	for (j = C; j > 2; j--)
	{
		A[ap[1]][j] = A[ap[1]][j - 1];
	}
	A[ap[1]][2] = 0;
}

int main()
{
	int i, j, t = 0;
	int answer = 0;

	cin >> R >> C >> T;
	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= C; j++)
		{
			cin >> A[i][j];
			if (A[i][j] == -1)
				ap[t++] = i;
		}
	}
	for (t = 0; t < T; t++)
	{
		spread_dust();
		run_top();
		run_bottom();
	}
	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= C; j++)
		{
			if (A[i][j] != -1)
				answer += A[i][j];
		}
	}
	cout << answer << endl;
	return 0;
}