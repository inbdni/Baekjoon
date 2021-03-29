#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> tip;

int main()
{
	int i, n;
	long long answer = 0;

	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> n;
		tip.push_back(n);
	}
	sort(tip.begin(), tip.end(), greater<int>());
	for (i = 0; i < N; i++)
	{
		if (tip[i] <= i)
			break;
		answer += tip[i] - i;
	}
	cout << answer << endl;
	return 0;
}