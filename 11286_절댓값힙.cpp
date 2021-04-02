#include <iostream>
#include <queue>

using namespace std;

struct cmp
{
	bool operator()(int a, int b)
	{
		if (abs(a) != abs(b))
			return abs(a) > abs(b);
		return a > b;
	}
};

int main() 
{
	priority_queue< int, vector<int>, cmp > heap;
	int N, num;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while (N--)
	{
		cin >> num;
		if (num)
		{
			heap.push(num);
			continue;
		}
		if (heap.empty())
		{
			cout << 0 << "\n";
		}
		else
		{
			cout << heap.top() << "\n";
			heap.pop();
		}
	}
	return 0;
}