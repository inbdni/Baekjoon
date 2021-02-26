#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int N;
int M;
int T;
deque<int> num[51];
bool check[51][51];

void rot(int x, int d, int k)
{
	int i, j, tmp;

	if (d)
	{
		for (i = 1; i * x <= N; i++)
		{
			for (j = 0; j < k; j++)
			{
				tmp = num[i * x].front();
				num[i * x].pop_front();
				num[i * x].push_back(tmp);
			}
		}
	}
	else
	{
		for (i = 1; i * x <= N; i++)
		{
			for (j = 0; j < k; j++)
			{
				tmp = num[i * x].back();
				num[i * x].pop_back();
				num[i * x].push_front(tmp);
			}
		}
	}
}

bool del()
{
	int i, j;
	bool res = false;
	
	memset(check, false, sizeof(check));
	for (i = 1; i <= N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (num[i][j] == 0)
			{
				continue;
			}
			if (i < N)
			{
				if (num[i][j] == num[i + 1][j])
				{
					check[i][j] = true;
					check[i + 1][j] = true;
				}
			}
			if (j == num[i].size() - 1)
			{
				if (num[i][j] == num[i][0])
				{
					check[i][j] = true;
					check[i][0] = true;
				}
			}
			else
			{
				if (num[i][j] == num[i][j + 1])
				{
					check[i][j] = true;
					check[i][j + 1] = true;
				}
			}
		}
	}
	for (i = 0; i <= N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (check[i][j])
			{
				num[i][j] = 0;
				res = true;
			}
		}
	}
	return res;
}

int op(bool flag)
{
	int i, j;
	int cnt = 0;
	int sum = 0;
	double avg;

	for (i = 1; i <= N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (num[i][j])
			{
				cnt++;
				sum += num[i][j];
			}
		}
	}
	if (flag)
	{
		return sum;
	}
	avg = (double)sum / cnt;
	for (i = 1; i <= N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (num[i][j] == 0)
				continue;
			if (num[i][j] < avg)
				num[i][j]++;
			else if (num[i][j] > avg)
				num[i][j]--;
		}
	}
	return 0;
}

int main()
{
	int i, j;
	int x, d, k;

	cin >> N >> M >> T;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			cin >> k;
			num[i].push_back(k);
		}
	}
	for (i = 1; i <= T; i++)
	{
		cin >> x >> d >> k;
		rot(x, d, k);
		if (!del())
		{
			op(0);
		}
	}
	cout << op(1) << endl;
	return 0;
}