#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct s_fish
{
	int r;
	int c;
	int dir;
	int alive;

	void init(int r, int c, int dir, bool alive)
	{
		this->r = r;
		this->c = c;
		this->dir = dir;
		this->alive = alive;
	}
};

int dr[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int answer;

bool in_range(s_fish p)
{
	if (p.r < 0 || p.r >= 4 || p.c < 0 || p.c >= 4)
		return false;
	return true;
}

vector<int> move_shark(vector< vector<int> > &space, s_fish shark)
{
	vector<int> fish_list;
	int fish_num;

	if (!shark.dir)
	{
		fish_list.push_back(space[0][0]);
	}
	else
	{
		while (1)
		{
			shark.r += dr[shark.dir];
			shark.c += dc[shark.dir];
			if (!in_range(shark))
				break;
			fish_num = space[shark.r][shark.c];
			if (fish_num > 0)
				fish_list.push_back(fish_num);
		}
	}
	return fish_list;
}

vector<s_fish> eat_fish(vector<s_fish> &fish, int fish_num)
{
	vector<s_fish> res;

	res.assign(fish.begin(), fish.end());
	res[0] = res[fish_num];
	res[fish_num].alive = false;
	return res;
}

vector< vector<int> > move_fish(vector< vector<int> > &space, vector <s_fish> &fish, int fish_num)
{
	vector< vector<int> > res;
	s_fish next;
	int i, tmp;
	bool check[9];
	bool flag;

	res.assign(space.begin(), space.end());
	res[fish[fish_num].r][fish[fish_num].c] = 0;
	for (i = 1; i < fish.size(); i++)
	{
		if (!fish[i].alive)
		{
			continue;
		}
		next = fish[i];
		memset(check, false, sizeof(check));
		flag = true;
		while(1)
		{
			if (check[next.dir])
			{
				flag = false;
				break;
			}
			check[next.dir] = true;
			next.r = fish[i].r + dr[next.dir];
			next.c = fish[i].c + dc[next.dir];
			if (in_range(next) && res[next.r][next.c] != 0)
			{
				break;
			}
			next.dir++;
			if (next.dir > 8)
			{
				next.dir = 1;
			}
		}
		if (flag)
		{
			tmp = res[next.r][next.c];
			if (tmp > 0)
			{
				fish[tmp].r = fish[i].r;
				fish[tmp].c = fish[i].c;
			}	
			res[fish[i].r][fish[i].c] = tmp;
			res[next.r][next.c] = i;
			fish[i] = next;
		}
	}
	return res;
}

void dfs(vector< vector<int> > space, vector<s_fish> fish, int sum)
{
	vector< vector<int> > new_space;
	vector<s_fish> new_fish;
	vector<int> fish_list;
	s_fish curr_fish;
	int i, fish_num;

	fish_list = move_shark(space, fish[0]);
	if (fish_list.empty())
	{
		answer = max(answer, sum);
		return;
	}
	space[fish[0].r][fish[0].c] = -1;
	for (i = 0; i < fish_list.size(); i++)
	{
 		fish_num = fish_list[i];
		new_fish = eat_fish(fish, fish_num);
		new_space = move_fish(space, new_fish, fish_num);
		dfs(new_space, new_fish, sum + fish_num);
	}	
}

int main()
{
	int i, j;
	int a, b;
	vector< vector<int> > space;
	vector<s_fish> fish;

	space.resize(4, vector<int> (4));
	fish.resize(17);
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			cin >> a >> b;
			space[i][j] = a;
			fish[a].init(i, j, b, true);
		}
	}
	dfs(space, fish, 0);
	cout << answer << endl;
	return 0;
}