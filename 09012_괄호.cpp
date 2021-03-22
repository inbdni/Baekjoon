#include <iostream>
#include <string>

using namespace std;

bool isVPS(string &ps)
{
	int i, cnt = 0;

	for (i = 0; i < ps.size(); i++)
	{
		if (ps[i] == '(')
			cnt++;
		else
			cnt--;
		if (cnt < 0)
			return false;
	}
	if (cnt != 0)
		return false;
	return true;
}

int main()
{
	int t, T;
	string ps;

	cin >> T;
	for (t = 0; t < T; t++)
	{
		cin >> ps;
		if (isVPS(ps))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}