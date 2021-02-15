#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

vector<int> stone;
set< vector<int> > check;
bool answer;

void bfs()
{
	queue< vector<int> > q;
	vector<int> tmp(3);
	int i, j;

	sort(stone.begin(), stone.end());
	check.insert(stone);
	q.push(stone);
	while (!q.empty())
	{
		stone = q.front();
		q.pop();
		if (stone[0] == stone[1] && stone[1] == stone[2])
		{
			answer = true;
			return;
		}
		for (i = 0; i < 2; i++)
		{
			for (j = i + 1; j < 3; j++)
			{
				if (stone[i] == stone[j])
				{
					continue;
				}
				tmp = stone;
				if (stone[i] < stone[j])
				{
					tmp[j] -= tmp[i];
					tmp[i] *= 2;
				}
				else
				{
					tmp[i] -= tmp[j];
					tmp[j] *= 2;
				}
				sort(tmp.begin(), tmp.end());
				if (!check.count(tmp))
				{
					check.insert(tmp);
					q.push(tmp);
				}
			}
		}
	}
}

int main()
{
	int i, tmp;

	for (i = 0; i < 3; i++)
	{
		cin >> tmp;
		stone.push_back(tmp);
	}
	bfs();
	cout << answer << endl;
	return 0;	
}