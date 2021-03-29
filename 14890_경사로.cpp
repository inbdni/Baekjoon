#include <iostream>

using namespace std;

int N;
int L;
int board[100][100];

int check_vertical(int n, int *s, int *e, int *cnt)
{
	*s = *e;
	*e += 1;
	while (*e < N && board[*e - 1][n] == board[*e][n])
		*e += 1;
	*cnt = *e - *s;
	return board[*e - 1][n];
}

int check_horizontal(int n, int *s, int *e, int *cnt)
{
	*s = *e;
	*e += 1;
	while (*e < N && board[n][*e - 1] == board[n][*e])
		*e += 1;
	*cnt = *e - *s;
	return board[n][*e - 1];
}

bool check(int n, bool flag)
{
	int s, e = 0;
	int a, b;
	int cnt1, cnt2;

	if (flag)
		a = check_vertical(n, &s, &e, &cnt1);
	else
		a = check_horizontal(n, &s, &e, &cnt1);
	while (e < N)
	{
		if (flag)
			b = check_vertical(n, &s, &e, &cnt2);
		else
			b = check_horizontal(n, &s, &e, &cnt2);
		if ((abs(a - b) != 1) || (a < b && cnt1 < L) || (a > b && cnt2 < L))
			return false;
		cnt1 = cnt2;
		if (a > b)
			cnt1 -= L;
		a = b;
	}
	return true;
}

int main()
{
	int i, j;
	int answer = 0;

	cin >> N >> L;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}
	for (i = 0; i < N; i++)
	{
		answer += check(i, 0);
		answer += check(i, 1);
	}
	cout << answer << endl;
	return 0;
}