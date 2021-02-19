#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int damage[3] = {9, 3, 1};
int d[61][61][61];

int dp(vector<int> scv)
{
	int i, res = 99;
	vector<int> tmp;

	sort(scv.begin(), scv.end());
	do
	{
		if (d[scv[0]][scv[1]][scv[2]] != -1)
		{
			res = min(res, d[scv[0]][scv[1]][scv[2]]);
		}
		else
		{
			tmp.clear();
			for (i = 0; i < scv.size(); i++)
			{
				tmp.push_back(max(scv[i] - damage[i], 0));
			}
			d[scv[0]][scv[1]][scv[2]] = dp(tmp) + 1;
			res = min(res, d[scv[0]][scv[1]][scv[2]]);
		}	
	} while (next_permutation(scv.begin(), scv.end()));
	return res;
}

int main()
{
	int i, tmp;
	vector<int> scv;

	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> tmp;
		scv.push_back(tmp);
	}
	memset(d, -1, sizeof(d));
	d[0][0][0] = 0;
	cout << dp(scv) << endl;
	return 0;
}