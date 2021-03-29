#include <iostream>
#include <climits>

using namespace std;

int N;
int ability[21][21];
bool selected[21];
int answer;

int get_diff()
{
	int i, j;
	int a = 0;
	int b = 0;

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (selected[i] != selected[j])
				continue;
			if (selected[i])
				a += ability[i][j];
			else
				b += ability[i][j];
		}
	}
	return abs(a - b);
}

void dfs(int num, int cnt)
{
	if (cnt == N / 2)
	{
		answer = min(answer, get_diff());
		return;
	}
	if (num > N)
	{
		return;
	}
	selected[num] = true;
	dfs(num + 1, cnt + 1);
	selected[num] = false;
	dfs(num + 1, cnt);
}

int main()
{
	int i, j;

	cin >> N;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			cin >> ability[i][j];
		}
	}
	answer = INT_MAX;
	dfs(1, 0);
	cout << answer << endl;
	return 0;
}