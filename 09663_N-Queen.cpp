#include <iostream>

using namespace std;

int N;
int board[15];
int answer;

void dfs(int n)
{
	int i, j;

	if (n > N)
	{
		answer++;
		return;
	}
	for (i = 1; i <= N; i++)
	{
		board[n] = i;
		for (j = 1; j < n; j++)
		{
			if (board[j] == i || abs(n - j) == abs(i - board[j]))
			{
				board[n] = 0;
				break;
			}
		}
		if (board[n])
			dfs(n + 1);
	}
}

int main()
{
	cin >> N;
	dfs(1);
	cout << answer << endl;
	return 0;
}