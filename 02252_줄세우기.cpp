#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node
{
	int edge;
	vector<int> next;
};

int N;
int M;
vector<node> line;

void topologicalSort()
{
	queue<int> q;
	int i, j, a, b;

	for (i = 1; i <= N; i++)
	{
		if (line[i].edge == 0)
			q.push(i);
	}
	while (!q.empty())
	{
		a = q.front();
		q.pop();
		cout << a << " ";
		for (j = 0; j < line[a].next.size(); j++)
		{
			b = line[a].next[j];
			line[b].edge--;
			if (line[b].edge == 0)
				q.push(b);
		}
	}
	cout << endl;
}

int main()
{
	int i, a, b;

	cin >> N >> M;
	line.resize(N + 1);
	for (i = 0; i < M; i++)
	{
		cin >> a >> b;
		line[a].next.push_back(b);
		line[b].edge++;
	}
	topologicalSort();
	return 0;
}