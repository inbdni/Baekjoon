#include <iostream>
#include <climits>

using namespace std;

int N;
int num[11];
int op[4];
int min_value = INT_MAX;
int max_value = INT_MIN;

void dfs(int op1, int op2, int op3, int op4, int idx, int result)
{
	if (idx == N)
	{
		min_value = min(min_value, result);
		max_value = max(max_value, result);
		return;
	}
	if (op1)
	{
		dfs(op1 - 1, op2, op3, op4, idx + 1, result + num[idx]);
	}
	if (op2)
	{
		dfs(op1, op2 - 1, op3, op4, idx + 1, result - num[idx]);
	}
	if (op3)
	{
		dfs(op1, op2, op3 - 1, op4, idx + 1, result * num[idx]);
	}
	if (op4)
	{
		dfs(op1, op2, op3, op4 - 1, idx + 1, result / num[idx]);
	}
}

int main()
{
	int i;

	cin >> N;
	if (N < 1 || N > 11)
	{
		return -1;
	}
	for (i = 0; i < N; i++)
	{
		cin >> num[i];
		if (num[i] < 1 || num[i] > 100)
		{
			return -1;
		}
	}
	for (i = 0; i < 4; i++)
	{
		cin >> op[i];
	}
	if (op[0] + op[1] + op[2] + op[3] != N - 1)
	{
		return -1;
	}
	dfs(op[0], op[1], op[2], op[3], 1, num[0]);
	cout << max_value << " " << min_value << endl;

	return 0;
}