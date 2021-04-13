#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct pos
{
	int r;
	int c;

	pos init(int r, int c)
	{
		this->r = r;
		this->c = c;
		return *this;
	}
};

int N;
int M;
int dist[101][14];
int h_size;
int s_size;
vector<pos> house;
vector<pos> store;
vector<bool> selected;

void make_permutation(int m)
{
	int i;

	selected.clear();
	for (i = 0; i < s_size - m; i++)
		selected.push_back(false);
	for (i = s_size - m; i < s_size; i++)
		selected.push_back(true);
}

void all_distance()
{
	int i, j;

	for (i = 0; i < h_size; i++)
		for (j = 0; j < s_size; j++)
			dist[i][j] = abs(house[i].r - store[j].r) + abs(house[i].c - store[j].c);
}

int house_distance(int num)
{
	int i, res = INT_MAX;

	for (i = 0; i < s_size; i++)
		if (selected[i])
			res = min(res, dist[num][i]);
	return res;
}

int city_distance()
{
	int i, res = 0;
	
	for (i = 0; i < h_size; i++)
		res += house_distance(i);
	return res;
}

int main()
{
	int i, j, value, answer = INT_MAX;
	pos p;

	cin >> N >> M;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			cin >> value;
			if (value == 1)
				house.push_back(p.init(i, j));
			if (value == 2)
				store.push_back(p.init(i, j));
		}
	}
	h_size = house.size();
	s_size = store.size();
	all_distance();
	for (i = 1; i <= M; i++)
	{
		make_permutation(i);
		do
		{
			answer = min(answer, city_distance());
		} while (next_permutation(selected.begin(), selected.end()));
	}
	cout << answer << endl;
	return 0;
}