#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N;
vector<long long> solution;
vector<long long> answer;

int main()
{
	int i, j;
	long long value, res = LONG_MAX;

	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> value;
		solution.push_back(value);
	}
	sort(solution.begin(), solution.end());
	i = 0;
	j = solution.size() - 1;
	while (i < j)
	{
		value = solution[i] + solution[j];
		if (abs(value) < res)
		{
			answer.clear();
			answer.push_back(solution[i]);
			answer.push_back(solution[j]);
			res = abs(value);
		}
		if (value > 0)
			j--;
		else
			i++;
	}
	cout << answer[0] << " " << answer[1] << endl;
	return 0;
}