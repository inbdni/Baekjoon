#include <iostream>
#include <queue>

using namespace std;

int F;
int S;
int G;
int U;
int D;
int dp[1000001];

int bfs()
{
	queue<int> q;
	int curr, next;
	int d[] = {U, -D};
	int i;

	dp[S] = 1;
	q.push(S);
	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		if (curr == G)
		{
			return dp[G] - 1;
		}
		for (i = 0; i < 2; i++)
		{
			next = curr + d[i];
			if (next < 1 || next > F || dp[next])
				continue;
			dp[next] = dp[curr] + 1;
			q.push(next);
		}
	}
	return -1;
}

int main()
{
	int res;

	cin >> F >> S >> G >> U >> D;
	res = bfs();
	if (res >= 0)
		cout << res << endl;
	else
		cout << "use the stairs" << endl;
	return 0;
}