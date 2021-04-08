#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> drink;

int main()
{
	int i, num;
	double sum;

	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> num;
		drink.push_back(num);
	}
	sort(drink.begin(), drink.end());
	sum = drink.back();
	for (i = 0; i < N - 1; i++)
	{
		sum += drink[i] / 2.0;
	}
	cout << sum << endl;
	return 0;
}