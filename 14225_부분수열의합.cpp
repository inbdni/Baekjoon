#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int num[20];
vector<int> is_possible;

void dfs(int i, int n, int sum)
{
	if (i > n)
	{
		return;
	}
	is_possible.push_back(sum);
	dfs(i + 1, n, sum + num[i]);
	dfs(i + 1, n, sum);
}

int main()
{
	int i;
	int answer = 1;

	cin >> N;
	if (N < 1 || N > 20)
	{
		return -1;
	}
	for (i = 0; i < N; i++)
	{
		cin >> num[i];
		if (num[i] > 100000)
		{
			return -1;
		}
	}
	dfs(0, N, 0);
	sort(is_possible.begin(), is_possible.end());
	is_possible.erase(unique(is_possible.begin(), is_possible.end()), is_possible.end());
	for (i = 1; i < is_possible.size(); i++)
	{
		if (is_possible[i] != i)
		{
			break;
		}
		answer++;
	}
	cout << answer << endl;

	return 0;
}
