#include <iostream>
#include <string>

using namespace std;

int N;
bool mine[10][10];	// 빈칸: 0, 지뢰: 1
bool click[10][10];	// 닫힘: 0, 열림: 1
bool finish;

void input()
{
	int i, j;
	string s;

	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> s;
		for (j = 0; j < N; j++)
		{
			if (s[j] == '*')
				mine[i][j] = true;
		}
	}
	for (i = 0; i < N; i++)
	{
		cin >> s;
		for (j = 0; j < N; j++)
		{
			if (s[j] == 'x')
			{
				click[i][j] = true;
				if (mine[i][j])
					finish = true;
			}
		}
	}
}

void print()
{
	int i, j, k;
	int nr, nc;
	int cnt;
	int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
	string s;

	for (i = 0; i < N; i++)
	{
		s.clear();
		for (j = 0; j < N; j++)
		{
			if (finish && mine[i][j])
			{
				s += '*';
				continue;
			}
			if (!click[i][j])
			{
				s += '.';
				continue;
			}
			cnt = 0;
			for (k = 0; k < 8; k++)
			{
				nr = i + dr[k];
				nc = j + dc[k];
				if (nr < 0 || nr >= N || nc < 0 || nc >= N)
					continue;
				if (mine[nr][nc])
					cnt++;
			}
			s += cnt + '0';	
		}
		cout << s << endl;
	}
}

int main()
{
	input();
	print();
	return 0;
}