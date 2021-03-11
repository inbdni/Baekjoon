#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

int prime[10000];
int visit[10000];
string s, e;

bool is_prime(int n)
{
	int i;

	for (i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int bfs()
{
	queue<string> q;
	string curr, next;
	char d[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	int i, j;

	memset(visit, -1, sizeof(visit));
	prime[stoi(s)] = 1;
	visit[stoi(s)] = 0;
	q.push(s);
	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		if (curr.compare(e) == 0)
			return visit[stoi(curr)];
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (i == 0 && j == 0)
					continue;
				next = curr;
				next[i] = d[j];
				if (visit[stoi(next)] != -1)
					continue;
				if (prime[stoi(next)] == -1)
					prime[stoi(next)] = is_prime(stoi(next));
				if (!prime[stoi(next)])
					continue;
				visit[stoi(next)] = visit[stoi(curr)] + 1;
				q.push(next);
			}
		}
	}
	return -1;
}

int main()
{
	int t, T;
	int res;

	cin >> T;
	memset(prime, -1, sizeof(prime));
	for (t = 0; t < T; t++)
	{
		s.clear();
		e.clear();
		cin >> s >> e;
		res = bfs();
		if (res < 0)
			cout << "Impossible" << endl;
		else
			cout << res << endl;
	}
	return 0;
}
