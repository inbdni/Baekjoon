#include <iostream>

using namespace std;

int N;
int K;
int coin[101];
long long money[100001];

void init()
{
	int i, j; 

	money[0] = 1;
	for (i = 0; i < N; i++)
	{
		for (j = coin[i]; j <= K; j++)
		{
			money[j] += money[j - coin[i]];
		}
	}
}

int main()
{
	int i;

	cin >> N >> K;
	for (i = 0; i < N; i++)
	{
		cin >> coin[i];
	}
	init();
	cout << money[K] << endl;
	return 0;
}