#include <iostream>

using namespace std;

int N;
int w[11];
bool selected[11];
int max_e;

void dfs(int n, int energy)
{
	int i, de;
	int left, right;

	if (n == 2)
	{
		max_e = max(max_e, energy);
		return;
	}
	for (i = 2; i < N; i++)
	{
		if (selected[i])
			continue;
		selected[i] = true;
		for (left = i - 1; selected[left] && left >= 1; left--);
		for (right = i + 1; selected[right] && right <= N; right++);
		de = energy + w[left] * w[right];
		dfs(n - 1, de);
		selected[i] = false;
	}
}

int main()
{
	int i;

	cin >> N;
	for (i = 1; i <= N; i++)
		cin >> w[i];
	dfs(N, 0);
	cout << max_e << endl;
	return 0;
}