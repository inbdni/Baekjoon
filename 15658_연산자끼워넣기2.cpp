#include <iostream>

using namespace std;

int N;
int A[12];
int op[4];
long long min_num = 1000000000;
long long max_num = -1000000000;

void dfs(int depth, int op1, int op2, int op3, int op4, long long res)
{
	if (depth > N)
	{
		min_num = min(min_num, res);
		max_num = max(max_num, res);
		return;
	}
	if (op1)
		dfs(depth + 1, op1 - 1, op2, op3, op4, res + A[depth]);
	if (op2)
		dfs(depth + 1, op1, op2 - 1, op3, op4, res - A[depth]);
	if (op3)
		dfs(depth + 1, op1, op2, op3 - 1, op4, res * A[depth]);
	if (op4)
		dfs(depth + 1, op1, op2, op3, op4 - 1, res / A[depth]);
}

int main()
{
	int i;

	cin >> N;
	for (i = 1; i <= N; i++)
	{
		cin >> A[i];
	}
	for (i = 0; i < 4; i++)
	{
		cin >> op[i];
	}
	dfs(2, op[0], op[1], op[2], op[3], A[1]);
	cout << max_num << endl << min_num << endl;
	return 0;
}
