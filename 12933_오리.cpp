#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str;
string target = "quack";
int res;

bool get_count()
{
	vector<int> duck;
	int s, e, i;
	int idx = 0;

	while (idx < str.size())
	{
		s = find(target.begin(), target.end(), str[idx]) - target.begin();
		e = s;
		while (idx < str.size() && e < target.size() && str[idx] == target[e])
		{
			idx++;
			e++;
		}
		if (s == 0)
		{
			duck.push_back(e);
			res = max(res, (int)duck.size());
			if (e - s == target.size())
				duck.pop_back();
			continue;
		}
		i = find(duck.begin(), duck.end(), s) - duck.begin();
		if (i == duck.size())
		{
			return false;
		}
		duck[i] = e;
		if (e == target.size())
		{
			duck.erase(duck.begin() + i);
		}	
	}
	if (!duck.empty())
		return false;
	return true;
}

int main() 
{
	cin >> str;
	if (get_count())
		cout << res << endl;
	else
		cout << -1 << endl;
	return 0;
}