#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct pos
{
	int r;
	int c;
	int destroy;
	bool day;

	void init(int r, int c, int destroy, bool day)
	{
		this->r = r;
		this->c = c;
		this->destroy = destroy;
		this->day = day;
	}
};

int N;
int M;
int K;
int map[1001][1001];		// 지도
int dp[1001][1001][11][2];	// 최단 경로 및 방문여부
int d[] = {-1, 1, 0, 0};

// 좌표가 범위 내인지 확인
bool in_range(pos p)
{
	if (p.r < 1 || p.r > N || p.c < 1 || p.c > M)
		return false;
	return true;
}

int bfs()
{
	queue<pos> q;
	pos curr, next;
	int i;

	// 출발지 삽입, 출발지도 포함하므로 최단 경로는 1
	next.init(1, 1, 0, true);
	dp[next.r][next.c][next.destroy][next.day] = 1;
	q.push(next);
	while (!q.empty())
	{
		curr = q.front();
		q.pop();

		// 도착지인 경우 최단 경로를 리턴
		if (curr.r == N && curr.c == M)
		{
			return dp[curr.r][curr.c][curr.destroy][curr.day];
		}

		// 상하좌우에 대하여
		for (i = 0; i < 4; i++)
		{
			next.init(curr.r + d[i], curr.c + d[3 - i], curr.destroy, !curr.day);

			// 범위 밖이면 패스
			if (!in_range(next))
			{
				continue;
			}

			// 벽인 경우
			if (map[next.r][next.c])
			{
				// 더 이상 벽을 부술 수 없으면 패스
				if (curr.destroy >= K)
				{
					continue;
				}
				// 낮이면 벽을 부수고 이동함
				if (curr.day)
				{
					next.destroy++;
				}
				// 밤이면 이동하지 않고 머무름
				else
				{
					next.r -= d[i];
					next.c -= d[3 - i];
				}
			}

			// 이미 방문한 적이 있으면 패스
			if (dp[next.r][next.c][next.destroy][next.day])
			{
				continue;
			}

			// 최단 경로를 저장하고 큐에 삽입
			dp[next.r][next.c][next.destroy][next.day] = dp[curr.r][curr.c][curr.destroy][curr.day] + 1;
			q.push(next);
		}
	}

	// 도착지에 가지 못하는 경우
	return -1;
}

int main()
{
	int i, j;
	string s;

	cin >> N >> M >> K;
	for (i = 1; i <= N; i++)
	{
		cin >> s;
		for (j = 1; j <= M; j++)
		{
			map[i][j] = s[j - 1] - '0';
		}
	}
	cout << bfs() << endl;
	return 0;
}