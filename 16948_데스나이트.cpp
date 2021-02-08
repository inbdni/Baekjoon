#include <iostream>
#include <queue>

using namespace std;

int N;
int night[2][2];
bool visited[201][201];
int dr[] = {-2, -2, 0, 0, 2, 2};
int dc[] = {-1, 1, -2, 2, -1, 1};

int bfs()
{
	queue< pair<int, int> > q;
	int i, j, size, res = 0;
	int r, c, nr, nc;

	visited[night[0][0]][night[0][1]] = true;
	q.push(make_pair(night[0][0], night[0][1]));
	while (!q.empty())
	{
		res++;
		size = q.size();
		for (i = 0; i < size; i++)
		{
			r = q.front().first;
			c = q.front().second;
			q.pop();
			for (j = 0; j < 6; j++)
			{
				nr = r + dr[j];
				nc = c + dc[j];
				if (nr == night[1][0] && nc == night[1][1])
				{
					return res;
				}
				if (nr > 0 && nr <= N && nc > 0 && nc <= N)
				{
					if (!visited[nr][nc])
					{
						visited[nr][nc] = true;
						q.push(make_pair(nr, nc));
					}
				}
			}
		}
	}
	return -1;
}

int main()
{
	cin >> N;
	cin >> night[0][0] >> night[0][1];
	cin >> night[1][0] >> night[1][1];
	cout << bfs() << endl;
	return 0;
}
