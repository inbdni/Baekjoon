#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int N;
bool check[26];

bool is_group(string &s)
{
	int i, idx;
	char prev = 0;

	memset(check, false, sizeof(check));
	for (i = 0; i < s.size(); i++)
	{
		if (s[i] == prev)
			continue;
		idx = s[i] - 'a';
		if (check[idx])
			return false;
		check[idx] = true;
		prev = s[i];
	}
	return true;
}

int main()
{
	int i, res = 0;
	string s;

	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> s;
		if (is_group(s))
			res++;
	}
	cout << res << endl;
	return 0;
}