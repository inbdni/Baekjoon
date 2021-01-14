#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> edge[100001];
int order[100001];
int cnt;
bool visited[1000001];
bool answer;

bool compare(int a, int b)
{
	if (order[a] < order[b])
		return true;
	return false;
}

void dfs(int node)
{
	int i;

	cnt++;
	visited[node] = true;
	if (order[node] != cnt)
		return;
	if (cnt == N)
	{
		answer = true;
		return;
	}
	for (i = 0; i < edge[node].size(); i++)
	{
		if (!visited[edge[node][i]])
			dfs(edge[node][i]);
	}
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
	dfs(1);
	cout << answer << endl;

	return 0;
}