#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N;
int M;
int zero_area;
int d[] = {1, -1, 0, 0};
int map[1001][1001];
bool visit[1001][1001];
vector<int> zero;

void bfs(int n, int m)
{
	queue< pair<int, int> > q;
	int i, dn, dm, cnt = 0;

	q.push(make_pair(n, m));
	visit[n][m] = true;
	while (!q.empty())
	{
		cnt++;
		n = q.front().first;
		m = q.front().second;
		q.pop();
		map[n][m] = zero_area;
		{
			for (i = 0; i < 4; i++)
			{
				dn = n + d[i];
				dm = m + d[3 - i];
				if (dn < 0 || dn >= N || dm < 0 || dm >= M)
					continue;
				if (map[dn][dm] || visit[dn][dm])
					continue;
				q.push(make_pair(dn, dm));
				visit[dn][dm] = true;
			}
		}
	}
	zero.push_back(cnt);
	zero_area++;
}

int move(int n, int m)
{
	vector<bool> check;
	int i, dn, dm, res = 1;

	check.resize(zero.size(), false);
	for (i = 0; i < 4; i++)
	{
		dn = n + d[i];
		dm = m + d[3 - i];
		if (dn < 0 || dn >= N || dm < 0 || dm >= M)
			continue;
		if (check[map[dn][dm]])
			continue;
		res += zero[map[dn][dm]];
		check[map[dn][dm]] = true;
	}
	return res;
}

int main()
{
	int i, j;
	string s;

	cin >> N >> M;
	for (i = 0; i < N; i++)
	{
		cin >> s;
		for (j = 0; j < M; j++)
			map[i][j] = s[j] - '0';
	}
	zero.push_back(0);
	zero.push_back(0);
	zero_area = 2;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (!map[i][j])
				bfs(i, j);
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (map[i][j] == 1)
				cout << move(i, j) % 10;
			else
				cout << 0;
		}
		cout << endl;
	}
	return 0;
}