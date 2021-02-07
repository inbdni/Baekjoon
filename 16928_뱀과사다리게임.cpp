#include <iostream>
#include <queue>

using namespace std;

int N;
int M;
int map[101];
int d[101];

void bfs()
{
	queue<int> q;
	int i;
	int curr, next;

	q.push(1);
	d[1] = 0;
	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		for (i = 6; i > 0; i--)
		{
			next = curr + i;
			if (next > 100)
				continue;
			if (map[next])
				next = map[next];
			if (!d[next])
			{
				d[next] = d[curr] + 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	int i;
	int a, b;

	cin >> N >> M;
	for (i = 1; i <= N; i++)
	{
		cin >> a >> b;
		map[a] = b;
	}
	for (i = 1; i <= M; i++)
	{
		cin >> a >> b;
		map[a] = b;
	}
	bfs();
	cout << d[100] << endl;
	return 0;
}