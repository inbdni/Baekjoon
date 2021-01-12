#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int visited[3001];
int dist[3001];
vector<int> edge[3001];

int dfs(int curr, int prev)
{
	int i;
	int res;
	int next;

	if (visited[curr])
		return curr;
	visited[curr] = 1;
	for (i = 0; i < edge[curr].size(); i++)
	{
		next = edge[curr][i];
		if (next == prev)
			continue;
		res = dfs(next, curr);
		if (res == -2)
			return -2;
		if (res > 0)
		{
			visited[curr] = 2;
			if (res == curr)
				return -2;
			return res;
		}
	}
	return -1;
}

void bfs()
{
	queue<int> q;
	int i;
	int curr;
	int next;

	for (i = 1; i <= N; i++)
	{
		if (visited[i] == 2)
			q.push(i);
	}
	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		for(i = 0; i < edge[curr].size(); i++)
		{
			next = edge[curr][i];
			if (visited[next] == 2)
				continue;
			visited[curr] = 2;
			dist[next] = dist[curr] + 1;
			q.push(next);
		}
	}
}

int main()
{
	int i;
	int a;
	int b;
	int answer = 1;

	cin >> N;
	if (N < 3 || N > 3000)
	{
		return -1;
	}
	for (i = 0; i < N; i++)
	{
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(1, 0);
	bfs();
	for (i = 1; i <= N; i++)
	{
		cout << dist[i] << " ";
	}
	cout << endl;

	return 0;
}
