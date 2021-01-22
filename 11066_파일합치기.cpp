#include <iostream>
#include <climits>

using namespace std;

int T;
int K;
int cost[501];
int sum[501];
int m[501][501];

int main()
{
	int t, i;
	int start, mid, end, gap;

	cin >> T;
	for (t = 0; t < T; t++)
	{
		cin >> K;
		for (i = 1; i <= K; i++)
		{
			cin >> cost[i];
			sum[i] = sum[i - 1] + cost[i];
		}
		for (gap = 1; gap < K; gap++)
		{
			for (start = 1; start + gap <= K; start++)
			{
				end = start + gap;
				m[start][end] = INT_MAX;
				for (mid = start; mid < end; mid++)
				{
					m[start][end] = min(m[start][end], m[start][mid] + m[mid + 1][end] + sum[end] - sum[start - 1]);
				}
			}
		}
		cout << m[1][K] << endl;
	}
	return 0;
}