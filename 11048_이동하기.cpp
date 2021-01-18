#include <iostream>

using namespace std;

int N;
int M;
int candy[1001][1001];
int m[1001][1001];

int main()
{
	int x;
	int y;
	int prev;
	int answer;

	cin >> N >> M;
	if (N < 1 || N > 1000 || M < 1 || M > 1000)
	{
		return -1;
	}
	for (y = 1; y <= N; y++)
	{
		for (x = 1; x <= M; x++)
			cin >> candy[y][x];
	}
	for (y = 1; y <= N; y++)
	{
		for (x = 1; x <= M; x++)
		{
			prev = max(m[y - 1][x], max(m[y][x - 1], m[y - 1][x - 1]));
			m[y][x] = prev + candy[y][x];
		}
	}
	answer = m[N][M];
	cout << answer << endl;

	return 0;
}