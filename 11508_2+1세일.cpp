#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> cost;

int main()
{
	int i, num, res = 0;

	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> num;
		cost.push_back(num);
	}
	sort(cost.begin(), cost.end(), greater<int>());
	for (i = 0; i < cost.size(); i++)
	{
		if ((i + 1) % 3 == 0)
			continue;
		res += cost[i];
	}
	cout << res << endl;
	return 0;
}