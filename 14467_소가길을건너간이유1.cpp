#include <iostream>
#include <cstring>

using namespace std;

int N;
int loc[11];

int main()
{
	int i, n, l;
	int res = 0;

	cin >> N;
	memset(loc, -1, sizeof(loc));
	for (i = 0; i < N; i++)
	{
		cin >> n >> l;
		if (loc[n] == -1)
		{
			loc[n] = l;
		}
		else if (loc[n] != l)
		{
			loc[n] = l;
			res++;
		}
	}
	cout << res << endl;
	return 0;
}