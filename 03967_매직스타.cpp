#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

#define N	5
#define M	9
#define MAGIC	26

using namespace std;

string star[N];
string magic_star[N];
string per;

void make_per()
{
	bool check[12];
	int i, j;

	memset(check, false, sizeof(check));
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (star[i][j] == '.' || star[i][j] == 'x')
				continue;
			check[star[i][j] - 'A'] = true;
		}
	}
	for (i = 0; i < 12; i++)
	{
		if (!check[i])
			per += ('A' + i);
	}
}

void fill_star()
{
	int i, j, idx = 0;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (star[i][j] == 'x')
				magic_star[i][j] = per[idx++];
		}
	}
}

int convert(char c)
{
	return c - 'A' + 1;
}

bool is_magic()
{
	int i, j, r, c, sum;
	int sr[] = {1, 3, 0, 1, 0, 1};
	int sc[] = {1, 1, 4, 1, 4, 7};
	int dr[] = {0, 1, 1};
	int dc[] = {2, 1, -1};

	for (i = 0; i < 6; i++)
	{
		r = sr[i];
		c = sc[i];
		sum = 0;
		for (j = 0; j < 4; j++)
		{
			sum += convert(magic_star[r][c]);
			r += dr[i / 2];
			c += dc[i / 2];
		}
		if (sum != MAGIC)
			return false;
	}
	return true;
}

int main()
{
	int i;

	for (i = 0; i < N; i++)
	{
		cin >> star[i];
		magic_star[i] = star[i];
	}	
	make_per();
	do
	{
		fill_star();
		if (is_magic())
			break;
	} while (next_permutation(per.begin(), per.end()));
	for (i = 0; i < N; i++)
		cout << magic_star[i] << "\n";
	return 0;
}