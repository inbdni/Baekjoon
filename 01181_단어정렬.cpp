#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<string> v;

int cmp(string &a, string &b)
{
	if (a.size() != b.size())
		return a.size() < b.size();
	return a < b;
}

int main()
{
	int i;
	string s;

	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);
	cout << v.front() << endl;
	for (i = 1; i < v.size(); i++)
	{
		if (v[i - 1].compare(v[i]) == 0)
			continue;
		cout << v[i] << endl;
	}
	return 0;
}