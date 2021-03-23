#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue< int, vector<int>, greater<int> > rope;

int main()
{
	int i, r, size;
	int weight = 0;

	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> r;
		rope.push(r);
	}
	size = rope.size();
	while (!rope.empty())
	{
		r = rope.top();
		rope.pop();
		weight = max(weight, r * size);
		size--;
	}
	cout << weight << endl;
	return 0;
}