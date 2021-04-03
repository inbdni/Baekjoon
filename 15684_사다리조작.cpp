#include <iostream>

using namespace std;

int N;
int M;
int H;
int answer;
bool ladder[32][12];

bool game()
{
	int i, j, line;

	for (i = 1; i <= N; i++)
	{
		line = i;
		for (j = 1; j <= H; j++)
		{
			if (ladder[j][line - 1])
				line--;
			else if (ladder[j][line])
				line++;		
		}
		if (line != i)
		{
			return false;
		}	
	}
	return true;
}

void dfs(int height, int cnt)
{
	int i, j;

	if (cnt >= answer)
	{
		return;
	}
	if (game())
	{
		answer = min(answer, cnt);
		return;
	}	
	for (i = height; i <= H; i++)
	{
		for (j = 1; j < N; j++)
		{
			if (ladder[i][j - 1] || ladder[i][j] || ladder[i][j + 1])
				continue;
			ladder[i][j] = true;
			dfs(i, cnt + 1);
			ladder[i][j] = false;
		}
	}
}

int main()
{
	int i, a, b;

	cin >> N >> M >> H;
	for (i = 0; i < M; i++)
	{
		cin >> a >> b;
		ladder[a][b] = true;
	}
	answer = 4;
	dfs(1, 0);
	if (answer > 3)
		cout << -1 << endl;
	else
		cout << answer << endl;
	return 0;
}