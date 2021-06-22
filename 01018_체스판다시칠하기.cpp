#include <iostream>

using namespace std;

int N;
int M;
char board[51][51];

int coloring(int r, int c, int flag)
{
	int i, j, cnt = 0;
	char color[] = {'B', 'W'};

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (board[r + i][c + j] != color[flag])
				cnt++;
			flag = !flag;
		}
		flag = !flag;
	}
	return cnt;
}

int cut()
{
	int i, j, answer = 2e9;

	for (i = 0; i <= N - 8; i++)
	{
		for (j = 0; j <= M - 8; j++)
		{
			answer = min(answer, coloring(i, j, 0));
			answer = min(answer, coloring(i, j, 1));
		}
	}
	return answer;
}

int main()
{
	int i, j;

	cin >> N >> M;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}
    cout << cut() << endl;
	return 0;
}