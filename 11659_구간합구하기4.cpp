#include <iostream>

using namespace std;

int N;
int M;
int sum[100001];

int main()
{
	int i, j, num;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (i = 1; i <= N; i++)
	{
		cin >> num;
		sum[i] = sum[i - 1] + num;
	}
	while (M--)
	{
		cin >> i >> j;
		cout << sum[j] - sum[i - 1] << "\n";
	}
	return 0;
}