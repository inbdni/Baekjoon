#include <iostream>
#include <cmath>

using namespace std;

unsigned long long N;

int main()
{
	unsigned long long q;

	cin >> N;
	q = sqrt(N);
	if (q * q == N)
		cout << q << endl;
	else
		cout << q + 1 << endl;
	return 0;
}