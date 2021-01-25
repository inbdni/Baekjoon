#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N;
int L;
int R;
int A[101][101];
bool door[101][101][2];
bool visited[101][101];

bool check_range(int n)
{
	n = abs(n);
	if (n >= L && n <= R)
		return true;
	return false;
}

bool open()
{
	bool res = false;
	int i, j, curr;

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			curr = A[i][j];
			if (i < N && check_range(curr - A[i + 1][j]))
			{
				res = true;
				door[i][j][0] = 1;
			}
			if (j < N && check_range(curr - A[i][j + 1]))
			{
				res = true;
				door[i][j][1] = 1;
			}
		}
	}
	return res;
}

void move(int i, int j)
{
	queue< pair<int, int> > q1;
	queue< pair<int, int> > q2;
	int sum = 0;
	int cnt = 0;

	visited[i][j] = true;
	q1.push(make_pair(i, j));
	sum += A[i][j];
	cnt++;
	while (!q1.empty())
	{
		i = q1.front().first;
		j = q1.front().second;
		q2.push(q1.front());
		q1.pop();
		if (i < N && door[i][j][0] && !visited[i + 1][j])
		{
			visited[i + 1][j] = true;
			q1.push(make_pair(i + 1, j));
			sum += A[i + 1][j];
			cnt++;
		}
		if (j < N && door[i][j][1] && !visited[i][j + 1])
		{
			visited[i][j + 1] = true;
			q1.push(make_pair(i, j + 1));
			sum += A[i][j + 1];
			cnt++;
		}
		if (i > 0 && door[i - 1][j][0] && !visited[i - 1][j])
		{
			visited[i - 1][j] = true;
			q1.push(make_pair(i - 1, j));
			sum += A[i - 1][j];
			cnt++;
		}
		if (j > 0 && door[i][j - 1][1] && !visited[i][j - 1])
		{
			visited[i][j - 1] = true;
			q1.push(make_pair(i, j - 1));
			sum += A[i][j - 1];
			cnt++;
		}
	}
	sum = sum / cnt;
	while (!q2.empty())
	{
		i = q2.front().first;
		j = q2.front().second;
		q2.pop();
		A[i][j] = sum;
	}
}

int main()
{
	bool cont;
	int i, j;
	int answer = 0;

	cin >> N >> L >> R;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
			cin >> A[i][j];
	}
	while (1)
	{
		memset(door, 0, sizeof(door));
		memset(visited, 0, sizeof(visited));
		cont = open();
		if (!cont)
			break;
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				if (!visited[i][j] && (door[i][j][0] || door[i][j][1]))
					move(i, j);
			}
		}
		answer += cont;
	}
	cout << answer << endl;
	return 0;
}