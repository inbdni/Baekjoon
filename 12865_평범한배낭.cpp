#include <iostream>
#include <vector>

using namespace std;

int N;
int K;
vector< pair<int, int> > wv;
int d[101][100001];

int dp()
{
	int i, j;

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= K; j++)
		{
			if (j < wv[i].first)
			{
				d[i][j] = d[i - 1][j];
			}
			else
			{
				d[i][j] = max(d[i - 1][j - wv[i].first] + wv[i].second, d[i - 1][j]);
			}
		}
	}
	return d[N][K];
}

int main()
{
	int i, w, v;

	cin >> N >> K;
	wv.push_back(make_pair(0, 0));
	for (i = 1; i <= N; i++)
	{
		cin >> w >> v;
		wv.push_back(make_pair(w, v));
	}
	cout << dp() << endl;
	return 0;
}