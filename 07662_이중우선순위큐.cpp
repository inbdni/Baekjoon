#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> T;

priority_queue< T, vector<T>, greater<T> > min_pq;
priority_queue< T, vector<T>, less<T> > max_pq;
bool exist[1000001];

void insert(int value, int idx)
{
	min_pq.push(make_pair(value, idx));
	max_pq.push(make_pair(value, idx));
	exist[idx] = true;
}

void delete_min()
{
	while (!min_pq.empty() && !exist[min_pq.top().second])
		min_pq.pop();
	if (min_pq.empty())
		return;
	exist[min_pq.top().second] = false;
	min_pq.pop();
}

void delete_max()
{
	while (!max_pq.empty() && !exist[max_pq.top().second])
		max_pq.pop();
	if (max_pq.empty())
		return;
	exist[max_pq.top().second] = false;
	max_pq.pop();
}

void get_result()
{
	while (!min_pq.empty() && !exist[min_pq.top().second])
		min_pq.pop();
	while (!max_pq.empty() && !exist[max_pq.top().second])
		max_pq.pop();
	if (min_pq.empty())
		cout << "EMPTY" << "\n";
	else
		cout << max_pq.top().first << " " << min_pq.top().first << "\n";
}

void clear_all()
{
	while (!min_pq.empty())
		min_pq.pop();
	while (!max_pq.empty())
		max_pq.pop();
	memset(exist, false, sizeof(exist));
}

int main()
{
	int t, k, idx, value;
	char cmd;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--)
	{
		cin >> k;
		idx = 0;
 		while (k--)
		{
			cin >> cmd >> value;
			if (cmd == 'I')
				insert(value, idx++);
			else if (value == -1)
				delete_min();
			else
				delete_max();
		}
		get_result();
		clear_all();
	}
	return 0;
}