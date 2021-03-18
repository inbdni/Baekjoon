#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

struct pos
{
	int r;
	int c;

	void init(int r, int c)
	{
		this->r = r;
		this->c = c;
	}
};

int N;
int M;
int lab[51][51];
int inactive;
vector<pos> birus;

string make_permutation()
{
	string res = "";
	int i;

	for (i = 0; i < M; i++)
		res += '1';
	for (i = M; i < birus.size(); i++)
		res += '0';
	sort(res.begin(), res.end());
	return res;
}

bool in_range(pos p)
{
	if (p.r < 0 || p.r >= N || p.c < 0 || p.c >= N)
		return false;
	return true;
}

int spreed_birus(string per)
{
	queue<pos> q;
	pos curr, next;
	int visit[51][51];
	int d[] = {-1, 1, 0, 0};
	int cnt = 0;
	int i, time = 0;

	memset(visit, -1, sizeof(visit));
	for (i = 0; i < per.size(); i++)
	{
		if (per[i] == '1')
		{
			next = birus[i];
			visit[next.r][next.c] = 0;
			q.push(next);
		}
	}
	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		cnt++;
		for (i = 0; i < 4; i++)
		{
			next.init(curr.r + d[i], curr.c + d[3 - i]);
			if (!in_range(next))
				continue;
			if (lab[next.r][next.c] == 1)
				continue;
			if (visit[next.r][next.c] != -1)
				continue;
			visit[next.r][next.c] = visit[curr.r][curr.c] + 1;
			q.push(next);
			time = visit[next.r][next.c];
		}
	}
	if (cnt == inactive)
		return time;
	return -1;
}

int main()
{
	int i, j;
	int res, answer = INT_MAX;
	string per = "";
	pos p;

	cin >> N >> M;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> lab[i][j];
			if (lab[i][j] == 0)
			{
				inactive++;
			}
			if (lab[i][j] == 2)
			{
				p.init(i, j);
				birus.push_back(p);
				lab[i][j] = 0;
				inactive++;
			}
		}
	}
	per = make_permutation();
	do
	{
		res = spreed_birus(per);
		if (res != -1)
			answer = min(answer, res);
	} while (next_permutation(per.begin(), per.end()));
	if (answer == INT_MAX)
		cout << -1 << endl;
	else
		cout << answer << endl;
	return 0;
}