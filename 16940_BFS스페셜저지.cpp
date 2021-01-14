#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<int> edge[100001];
int order[100001];
bool visited[1000001];
bool answer;

bool compare(int a, int b)
{
	if (order[a] < order[b])
		return true;
	return false;
}

void bfs()
{
	queue<int> q;
	int i = 1;
	int j;
	int node = 1;

	if (order[node] != i)
	{
		return;
	}
	i++;
	visited[node] = true;
	q.push(node);
	while (!q.empty())
	{
		node = q.front();
		q.pop();
		for (j = 0; j < edge[node].size(); j++)
		{
			if (visited[edge[node][j]])
				continue;
			if (order[edge[node][j]] != i)
				return;
			i++;
			visited[edge[node][j]] = true;
			q.push(edge[node][j]);
		}
	}
	if (i == N + 1)
		answer = true;
}

int main()
{
	int i;
	int a;
	int b;

	cin >> N;
	if (N < 2 || N > 100000)
	{
		return -1;
	}
	for (i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (i = 1; i <= N; i++)
	{
		cin >> a;
		order[a] = i;
	}
	for (i = 1; i <= N; i++)
	{
		sort(edge[i].begin(), edge[i].end(), compare);
	}
	bfs();
	cout << answer << endl;

	return 0;
}