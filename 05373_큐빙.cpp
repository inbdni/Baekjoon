#include <iostream>
#include <string>

#define	U	0
#define	D	1
#define	F	2
#define	B	3
#define	L	4
#define	R	5

using namespace std;

char cube[54];
char color[] = {'w', 'y', 'r', 'o', 'g', 'b'};
int rot[] = {0, 1, 2, 5, 8, 7, 6, 3};
int turn[6][4][3] = {
	{ {36, 37, 38}, {18, 19, 20},	{45, 46, 47},	{27, 28, 29} },
	{ {33, 34, 35},	{51, 52, 53},	{24, 25, 26},	{42, 43, 44} },
	{ {6, 7, 8},	{44, 41, 38},	{11, 10, 9},	{45, 48, 51} },
	{ {2, 1, 0},	{53, 50, 47},	{15, 16, 17},	{36, 39, 42} },
	{ {0, 3, 6},	{35, 32, 29},	{9, 12, 15},	{18, 21, 24} },
	{ {8, 5, 2},	{26, 23, 20},	{17, 14, 11},	{27, 30, 33} }
};

void init()
{
	int i;

	for (i = 0; i < 54; i++)
		cube[i] = color[i / 9];
}

int convert(char c)
{
	if (c == 'U')	return U;
	if (c == 'D')	return D;
	if (c == 'F')	return F;
	if (c == 'B')	return B;
	if (c == 'L')	return L;
	if (c == 'R')	return R;
}

void rot_plus(int space)
{
	int i;
	char tmp[8];

	for (i = 0; i < 8; i++)
		tmp[i] = cube[space * 9 + rot[i]];
	for (i = 0; i < 8; i++)
		cube[space * 9 + rot[(i + 2) % 8]] = tmp[i];
}

void rot_minus(int space)
{
	int i;
	char tmp[8];

	for (i = 0; i < 8; i++)
		tmp[i] = cube[space * 9 + rot[i]];
	for (i = 0; i < 8; i++)
		cube[space * 9 + rot[i]] = tmp[(i + 2) % 8];
}

void turn_plus(int space)
{
	int i, j;
	char tmp[3];

	rot_plus(space);
	for (j = 0; j < 3; j++)
		tmp[j] = cube[turn[space][0][j]];
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			cube[turn[space][i][j]] = cube[turn[space][i + 1][j]];
	}
	for (j = 0; j < 3; j++)
		cube[turn[space][3][j]] = tmp[j];
}

void turn_minus(int space)
{
	int i, j;
	char tmp[3];

	rot_minus(space);
	for (j = 0; j < 3; j++)
		tmp[j] = cube[turn[space][3][j]];
	for (i = 3; i > 0; i--)
	{
		for (j = 0; j < 3; j++)
			cube[turn[space][i][j]] = cube[turn[space][i - 1][j]];
	}
	for (j = 0; j < 3; j++)
		cube[turn[space][0][j]] = tmp[j];
}

void print()
{
	int i;

	for (i = 0; i < 9; i++)
	{
		cout << cube[i];
		if ((i + 1) % 3 == 0)
			cout << "\n";
	}
}

int main()
{
	int T, N;
	int t, n;
	string s;

	cin >> T;
	for (t = 0; t < T; t++)
	{
		cin >> N;
		init();
		for (n = 0; n < N; n++)
		{
			cin >> s;
			if (s[1] == '+')
				turn_plus(convert(s[0]));
			else
				turn_minus(convert(s[0]));
		}
		print();
	}
	return 0;
}