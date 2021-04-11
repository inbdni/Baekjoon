#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct pos
{
	int r;
	int c;
};

int N;
int M;
int K;
string board[10];
unordered_map<string, int> cnt;

bool in_range(pos p)
{
	if (p.r < 0 || p.r >= N || p.c < 0 || p.c >= M)
		return false;
	return true;
}

pos get_pos(pos curr, int d)
{
	int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
	int dc[] = {0, 1, 1 ,1, 0, -1, -1, -1};
	pos next;

	next.r = curr.r + dr[d];
	next.c = curr.c + dc[d];
	if (next.r < 0)		next.r = N - 1;
	if (next.r >= N) 	next.r = 0;
	if (next.c < 0)		next.c = M - 1;
	if (next.c >= M)	next.c = 0;
	return next;
}

void dfs(pos curr, string s)
{
	int i;

	s += board[curr.r][curr.c];
	cnt[s]++;
	if (s.size() == 5)
		return;
	for (i = 0; i < 8; i++)
		dfs(get_pos(curr, i), s);
}

int main()
{
	int i;
	string s;
	pos p;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (i = 0; i < N; i++)
	{
		cin >> board[i];
	}
	for (p.r = 0; p.r < N; p.r++)
	{
		for (p.c = 0; p.c < M; p.c++)
		{
			dfs(p, "");
		}	
	}
	for (i = 0; i < K; i++)
	{
		cin >> s;
		cout << cnt[s] << "\n";
	}
	return 0;
}