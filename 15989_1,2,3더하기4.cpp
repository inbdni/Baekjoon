#include <iostream>

using namespace std;

int T;
int m[10001][3];

int main()
{
	int i;
	int n;

	cin >> T;
	m[1][0] = 1;
	m[2][0] = 1;
	m[2][1] = 1;
	m[3][0] = 1;
	m[3][1] = 1;
	m[3][2] = 1;
	for (i = 4; i <= 10000; i++)
	{
		m[i][0] = m[i - 1][0];
		m[i][1] = m[i - 2][1] + m[i - 2][0];
		m[i][2] = m[i - 3][2] + m[i - 3][1] + m[i - 3][0];
	}
	for (i = 0; i < T; i++)
	{
		cin >> n;
		cout << m[n][0] + m[n][1] + m[n][2] << endl;
	}
	return 0;
}