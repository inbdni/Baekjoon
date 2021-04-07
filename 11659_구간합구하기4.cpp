#include <iostream>

using namespace std;

int N;
int M;
int num[100001];
int sum[100001];

int get_sum(int a, int b)
{
	return sum[b] - sum[a - 1];
}

int main()
{
	int i, j;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (i = 1; i <= N; i++)
	{
		cin >> num[i];
		sum[i] = sum[i - 1] + num[i];
	}
	while (M--)
	{
		cin >> i >> j;
		cout << get_sum(i, j) << "\n";
	}
	return 0;
}