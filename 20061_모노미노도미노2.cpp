#include <iostream>
#include <vector>

using namespace std;

int N;
vector< vector<int> > green;
vector< vector<int> > blue;

void put_block(int t, int x, int y)
{
	int gx = -1;
	int by = -1;

	if (t == 1)
	{
		while (gx < 5 && green[gx + 1][y] == 0)
			gx++;
		green[gx][y] = 1;
		while (by < 5 && blue[by + 1][x] == 0)
			by++;
		blue[by][x] = 1;
	}
	else if (t == 2)
	{
		while (gx < 5 && green[gx + 1][y] == 0 && green[gx + 1][y + 1] == 0)
			gx++;
		green[gx][y] = 2;
		green[gx][y + 1] = 2;
		while (by < 5 && blue[by + 1][x] == 0)
			by++;
		blue[by - 1][x] = 2;
		blue[by][x] = 2;
	}
	else
	{
		while (gx < 5 && green[gx + 1][y] == 0)
			gx++;
		green[gx - 1][y] = 3;
		green[gx][y] = 3;
		while (by < 5 && blue[by + 1][x] == 0 && blue[by + 1][x + 1] == 0)
			by++;
		blue[by][x] = 3;
		blue[by][x + 1] = 3;
	}
}

int erase_line()
{
	int x, y, res = 0;

	for (x = 0; x < 6; x++)
	{
		for (y = 0; y < 4; y++)
		{
			if (green[x][y] == 0)
				break;
		}
		if (y == 4)
		{
			green.erase(green.begin() + x);
			green.insert(green.begin(), vector<int> (4, 0));
			res++;
		}
	}
	for (y = 0; y < 6; y++)
	{
		for (x = 0; x < 4; x++)
		{
			if (blue[y][x] == 0)
				break;
		}
		if (x == 4)
		{
			blue.erase(blue.begin() + y);
			blue.insert(blue.begin(), vector<int> (4, 0));
			res++;
		}
	}
	return res;
}

void push_line()
{
	int x, y;

	for (x = 0; x < 2; x++)
	{
		for (y = 0; y < 4; y++)
		{
			if (green[x][y])
				break;
		}
		if (y < 4)
		{
			green.pop_back();
			green.insert(green.begin(), vector<int> (4, 0));
		}
	}
	for (y = 0; y < 2; y++)
	{
		for (x = 0; x < 4; x++)
		{
			if (blue[y][x])
				break;
		}
		if (x < 4)
		{
			blue.pop_back();
			blue.insert(blue.begin(), vector<int> (4, 0));
		}
	}
}

int count_block()
{
	int r, c, res = 0;

	for (r = 0; r < 6; r++)
	{
		for (c = 0; c < 4; c++)
		{
			if (green[r][c])
				res++;
			if (blue[r][c])
				res++;
		}
	}
	return res;
}

int main()
{
	int t, x, y;
	int score = 0;

	cin >> N;
	green.resize(6, vector<int> (4));
	blue.resize(6, vector<int> (4));
	while (N--)
	{
		cin >> t >> x >> y;
		put_block(t, x, y);
		score += erase_line();
		push_line();
	}
	cout << score << endl;
	cout << count_block() << endl;
	return 0;
}
