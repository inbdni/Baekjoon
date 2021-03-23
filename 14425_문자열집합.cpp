#include <iostream>
#include <string>
#include <set>

using namespace std;

int N;
int M;
set<string> S;

int main()
{
	string s;
	int i, cnt = 0;

	cin >> N >> M;
	for (i = 0; i < N; i++)
	{
		cin >> s;
		S.insert(s);
	}
	for (i = 0; i < M; i++)
	{
		cin >> s;
		if (S.find(s) != S.end())
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}