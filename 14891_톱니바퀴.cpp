#include <iostream>
#include <string>
#include <deque>
#include <cstring>

#define L	6
#define	R	2

using namespace std;

int K;
deque<int> cogwheel[5];
bool check[5];

void turn(int num, int dir)
{
	int tmp;

	check[num] = true;
	if (num > 1 && !check[num - 1] && cogwheel[num - 1][R] != cogwheel[num][L])
		turn(num - 1, -dir);
	if (num < 4 && !check[num + 1] && cogwheel[num][R] != cogwheel[num + 1][L])
		turn(num + 1, -dir);
	if (dir == 1)
	{
		tmp = cogwheel[num].back();
		cogwheel[num].pop_back();
		cogwheel[num].push_front(tmp);
	}
	else
	{
		tmp = cogwheel[num].front();
		cogwheel[num].pop_front();
		cogwheel[num].push_back(tmp);
	}
}

int get_score()
{
	int i, res = 0;
	int score[] = {0, 1, 2, 4, 8};

	for (i = 1; i <= 4; i++)
	{
		if (cogwheel[i].front())
			res += score[i];
	}
	return res;
}

int main()
{
	int i, j, k;
	string s;

	for (i = 1; i <= 4; i++)
	{
		cin >> s;
		for (j = 0; j < 8; j++)
			cogwheel[i].push_back(s[j] - '0');
	}
	cin >> K;
	for (k = 0; k < K; k++)
	{
		cin >> i >> j;
		turn(i, j);
		memset(check, false, sizeof(check));
	}
	cout << get_score() << endl;
	return 0;
}