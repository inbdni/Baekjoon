#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

struct pos
{
	int r;
	int c;
	string d;

	void init(int r, int c, string d)
	{
		this->r = r;
		this->c = c;
		this->d = d;
	}
};

int N;
int M;
int answer;
vector<pos> cctv;

bool in_range(int r, int c)
{
	if (r < 0 || r >= N || c < 0 || c >= M)
		return false;
	return true;
}

vector< vector<int> > find_area(pos p, vector< vector<int> > &office)
{
	int i, nr, nc, num;
	int dr[] = {-1, 0, 1, 0};
	int dc[] = {0, 1, 0, -1};
	vector< vector<int> > res;

	num = office[p.r][p.c];
	res.assign(office.begin(), office.end());
	for (i = 0; i < 4; i++)
	{
		if (p.d[i] == '0')
		{
			continue;
		}
		nr = p.r;
		nc = p.c;
		while (1)
		{
			nr += dr[i];
			nc += dc[i];
			if (!in_range(nr, nc) || res[nr][nc] == 6)
				break;
			res[nr][nc] = num;
		}
	}
	return res;
}

int count_blind(vector< vector<int> > &office)
{
	int i, j, res = 0;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (!office[i][j])
				res++;
		}
	}
	return res;
}

void dfs(int idx, vector< vector<int> > office)
{
	pos p;
	set<string> check;

	if (idx == cctv.size())
	{
		answer = min(answer, count_blind(office));
		return;
	}
	p = cctv[idx];
	while (1)
	{
		if (check.find(p.d) != check.end())
			return;
		check.insert(p.d);
		dfs(idx + 1, find_area(p, office));
		p.d = p.d.substr(1) + p.d.front();
	}
}

int main()
{
	int i, j, num;
	pos p;
	string dir[] = {"", "1000", "1010", "1100", "1110", "1111"};
	vector< vector<int> > office;

	cin >> N >> M;
	office.resize(N, vector<int> (M));
	answer = N * M;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			cin >> office[i][j];
			num = office[i][j];
			if (num > 0 && num < 6)
			{
				p.init(i, j, dir[num]);
				cctv.push_back(p);
			}
		}
	}
	dfs(0, office);
	cout << answer << endl;
	return 0;
}