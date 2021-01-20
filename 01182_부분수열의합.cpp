#include <iostream>

using namespace std;

int N;
int S;
int num[20];

void dfs(int idx, int sum, int *answer)
{
	sum += num[idx];
	
	if (idx >= N)
	{
		return;
	}
	if (sum == S)
	{
		(*answer)++;
	}
	dfs(idx + 1, sum - num[idx], answer);
	dfs(idx + 1, sum, answer);
}

int main()
{
	int i;
	int answer = 0;

	cin >> N >> S;
	if (N < 1 || N > 20 || abs(S) > 1000000)
	{
		return -1;
	}
	for (i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	dfs(0, 0, &answer);
	cout << answer << endl;

	return 0;
}
