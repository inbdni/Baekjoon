#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> P;

int main()
{
	int i;
	int sum = 0;
	int answer = 0;

	cin >> N;
	P.resize(N);
	for (i = 0; i < N; i++)
	{
		cin >> P[i];
	}	
	sort(P.begin(), P.end());
	for (i = 0; i < N; i++)
	{
		answer += sum + P[i];
		sum += P[i];
	}
	cout << answer << endl;
	return 0;
}