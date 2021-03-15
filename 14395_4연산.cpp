#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

long long S;
long long T;
string answer = "";

long long calc(long long n, char op)
{
	if (op == '*')			return n * n;
	if (op == '+')			return n + n;
	if (op == '-')			return n - n;
	if (op && op == '/')	return n / n;
}

void bfs()
{
	queue< pair<long long, string> > q;
	pair<long long, string> curr;
	set<long long> check;
	char op[] = {'*', '+', '-', '/'};
	long long res;
	int i;

	check.insert(S);
	q.push(make_pair(S, ""));
	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		if (!answer.empty() && (curr.second.size() > answer.size()))
		{
			return;
		}
		if (curr.first == T)
		{
			if (answer.empty())
				answer = curr.second;
			else if (curr.second < answer)
				answer = curr.second;
		}
		for (i = 0; i < 4; i++)
		{
			res = calc(curr.first, op[i]);
			if (check.find(res) == check.end())
			{
				check.insert(res);
				q.push(make_pair(res, curr.second + op[i]));
			}
		}
	}
}

int main()
{
	cin >> S >> T;
	if (S == T)
	{
		cout << 0 << endl;
	}
	else
	{
		bfs();
		if (answer.empty())
			cout << -1 << endl;
		else
			cout << answer << endl;		
	}
	return 0;
}