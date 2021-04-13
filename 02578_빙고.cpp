#include <iostream>
#include <queue>

#define	HORIZONTAL	0
#define	VERTICAL	1
#define DIAGONAL	2

using namespace std;

struct pos
{
	int r;
	int c;
};

pos num[26];
int cnt[3][5];

int main()
{
	int i, j, n;
	int turn = 0;
	int line = 0;
	queue<int> q;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			cin >> n;
			num[n].r = i;
			num[n].c = j;
		}
	}
	for (i = 0; i < 25; i++)
	{
		cin >> n;
		q.push(n);
	}
	while (!q.empty() && line < 3)
	{
		turn++;
		n = q.front();
		q.pop();
		cnt[HORIZONTAL][num[n].r]++;
		if (cnt[HORIZONTAL][num[n].r] == 5)
			line++;
		cnt[VERTICAL][num[n].c]++;
		if (cnt[VERTICAL][num[n].c] == 5)
			line++;
		if (num[n].r == num[n].c)
		{
			cnt[DIAGONAL][0]++;
			if (cnt[DIAGONAL][0] == 5)
				line++;
		}
		if (num[n].r + num[n].c == 4)
		{
			cnt[DIAGONAL][1]++;
			if (cnt[DIAGONAL][1] == 5)
				line++;
		}
	}
	cout << turn << endl;
	return 0;
}