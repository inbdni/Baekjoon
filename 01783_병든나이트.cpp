#include <iostream>

using namespace std;

long long N;
long long M;

int main()
{
	long long cnt;

	cin >> N >> M;
	if (N == 1)
		cnt = 1;
	else if (N == 2)
		cnt = min((long long)4, (M + 1) / 2);
	else if (M < 7)
		cnt = min((long long)4, M);	
	else
		cnt = M - 2;
	cout << cnt << endl;
	return 0;
}