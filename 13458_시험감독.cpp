#include <iostream>

using namespace std;

int N;
int A[1000001];
int B;
int C;

int main()
{
	int i, num;
	long long answer;

	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	cin >> B >> C;
	answer = N;
	for (i = 0; i < N; i++)
	{
		num = A[i] - B;
		if (num > 0)
			answer += (num - 1) / C + 1;
	}
	cout << answer << endl;
	return 0;
}