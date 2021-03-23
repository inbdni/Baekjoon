#include <iostream>

using namespace std;

int main()
{
	int n, cnt = 0;

	cin >> n;
	while (n)
	{
		if (n % 5 == 0)
		{
			cnt += n / 5;
			break;
		}
		n -= 2;
		cnt++;
	}
	if (n < 0)
		cout << -1 << endl;
	else
		cout << cnt << endl;	
	return 0;
}