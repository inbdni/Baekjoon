#include <iostream>
#include <cstring>

using namespace std;

int N;
int M;
int S;
int E;
int num[2001];
int pal[2001][2001];

int dp(int S, int E)
{
	if (S >= E)
		return 1;
	if (pal[S][E] != -1)
		return pal[S][E];
	if (num[S] == num[E])
		pal[S][E] = dp(S + 1, E - 1);
	else
		pal[S][E] = 0;
	return pal[S][E];
}

int main()
{
	int i;

	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &num[i]);
	}
	scanf("%d", &M);
	memset(pal, -1, sizeof(pal));
	for (i = 1; i <= M; i++)
	{
		scanf("%d", &S);
		scanf("%d", &E);
		printf("%d\n", dp(S, E));
	}
	return 0;
}