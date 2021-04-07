#include <iostream>
#include <cstring>

using namespace std;

int N;
int A[21][21];
bool boundary[21][21];
int population[6];
int sum;

void find_boundary(int x, int y, int d1, int d2)
{
	int d;

	for (d = 0; d <= d1; d++)
	{
		boundary[x + d][y - d] = true;
		boundary[x + d2 + d][y + d2 - d] = true;
	}
	for (d = 0; d <= d2; d++)
	{
		boundary[x + d][y + d] = true;
		boundary[x + d1 + d][y - d1 + d] = true;
	}
}

void get_population(int x, int y, int d1, int d2)
{
	int r, c;

	population[5] = sum;
	for (r = 1; r < x + d1; r++)
	{
		for (c = 1; c <= y; c++)
		{
			if (boundary[r][c])
				break;
			population[1] += A[r][c];
		}
	}
	population[5] -= population[1];
	for (r = 1; r <= x + d2; r++)
	{
		for (c = N; c > y; c--)
		{
			if (boundary[r][c])
				break;
			population[2] += A[r][c];
		}
	}
	population[5] -= population[2];
	for (r = N; r >= x + d1; r--)
	{
		for (c = 1; c < y - d1 + d2; c++)
		{
			if (boundary[r][c])
				break;
			population[3] += A[r][c];
		}
	}
	population[5] -= population[3];
	for (r = N; r > x + d2; r--)
	{
		for (c = N; c >= y - d1 + d2; c--)
		{
			if (boundary[r][c])
				break;
			population[4] += A[r][c];
		}
	}
	population[5] -= population[4];
}

int get_gap()
{
	int min_value = 2e9;
	int max_value = 0;
	int i, res;

	for (i = 1; i <= 5; i++)
	{
		min_value = min(min_value, population[i]);
		max_value = max(max_value, population[i]);
	}
	res = max_value - min_value;
	return res;
}

int solution()
{
	int x, y;
	int d1, d2;
	int res = 2e9;

	for (x = 1; x <= N; x++)
	{
		for (y = 1; y <= N; y++)
		{
			for (d1 = 1; d1 <= y - 1; d1++)
			{
				for (d2 = 1; d2 <= N - y; d2++)
				{
					if (d1 + d2 <= N - x)
					{
						memset(boundary, 0, sizeof(boundary));
						memset(population, 0, sizeof(population));
						find_boundary(x, y, d1, d2);
						get_population(x, y, d1, d2);
						res = min(res, get_gap());
					}
				}
			}
		}
	}
	return res;
}

int main()
{
	int r, c;
	
	cin >> N;
	for (r = 1; r <= N; r++)
	{
		for (c = 1; c <= N; c++)
		{
			cin >> A[r][c];
			sum += A[r][c];
		}
	}
	cout << solution() << endl;
	return 0;
}