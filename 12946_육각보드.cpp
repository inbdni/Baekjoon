#include <iostream>
#include <algorithm>

using namespace std;

int N;
int color;
char selected[50][50];
int colored[50][50];
int dy[] = {-1, -1, 0, 0, 1, 1};
int dx[] = {0, 1, -1, 1, -1, 0};

void coloring(int i, int j, int c)
{
	int k;
	int ny;
	int nx;

	colored[i][j] = c + 1;
	color = max(color, 1);
	for (k = 0; k < 6; k++)
	{
		ny = i + dy[k];
		nx = j + dx[k];
		if (!(ny >= 0 && ny < N && nx >= 0 && nx < N))
			continue;
		if (selected[ny][nx] == '-')
			continue;
		if (colored[ny][nx] == 0)
			coloring(ny, nx, 1 - c);
		color = max(color, 2);
		if (colored[ny][nx] == c + 1)
			color = max(color, 3);
	}
}

int main(void)
{
	int i;
	int j;
	string line;

	cin >> N;
	if (N < 1 || N > 50)
	{
		return -1;
	}	
	for (i = 0; i < N; i++)
	{
		cin >> line;
		for (j = 0; j < N; j++)
			selected[i][j] = line[j];
		line.clear();
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (selected[i][j] == 'X' && colored[i][j] == 0)
				coloring(i, j, 0);
		}
	}
	cout << color << endl;
	return 0;
}
