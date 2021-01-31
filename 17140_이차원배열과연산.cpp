#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int R;
int C;
int K;
int r_size;
int c_size;
int A[101][101];

unordered_map<int, int> um;
unordered_map<int, int>::iterator it;
vector< pair<int, int> > tmp;

void r_sorting()
{
	int i, j;
	int size, curr = c_size;
	
	for (i = 1; i <= r_size; i++)
	{
		for (j = 1; j <= curr; j++)
		{
			if (A[i][j] != 0)
				um[A[i][j]]++;
		}
		for (it = um.begin(); it != um.end(); it++)
		{
			tmp.push_back(make_pair(it->second, it->first));
		}
		sort(tmp.begin(), tmp.end());
		size = tmp.size();
		if (size > 50) size = 50;
		for (j = 0; j < size; j++)
		{
			A[i][2 * j + 1] = tmp[j].second;
			A[i][2 * j + 2] = tmp[j].first;
		}
		for (j = size * 2 + 1; j <= curr; j++)
			A[i][j] = 0;
		if (c_size < size * 2)
			c_size = size * 2;
		um.clear();
		tmp.clear();
	}
}

void c_sorting()
{
	int i, j;
	int size, curr = r_size;
	
	for (i = 1; i <= c_size; i++)
	{
		for (j = 1; j <= curr; j++)
		{
			if (A[j][i] != 0)
				um[A[j][i]]++;
		}
		for (it = um.begin(); it != um.end(); it++)
		{
			tmp.push_back(make_pair(it->second, it->first));
		}
		sort(tmp.begin(), tmp.end());
		size = tmp.size();
		if (size > 50) size = 50;
		for (j = 0; j < size; j++)
		{
			A[2 * j + 1][i] = tmp[j].second;
			A[2 * j + 2][i] = tmp[j].first;
		}
		for (j = size * 2 + 1; j <= curr; j++)
			A[j][i] = 0;
		if (r_size < size * 2)
			r_size = size * 2;
		um.clear();
		tmp.clear();
	}
}

int main()
{
	int i, j;

	cin >> R >> C >> K;
	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 3; j++)
		{
			cin >> A[i][j];
		}
	}
	r_size = 3;
	c_size = 3;
	for (i = 0; i <= 100; i++)
	{
		if (A[R][C] == K)
			break;
		if (r_size >= c_size)
			r_sorting();
		else
			c_sorting();
	}
	if (i > 100)
		cout << -1 << endl;
	else
		cout << i << endl;
	return 0;
}