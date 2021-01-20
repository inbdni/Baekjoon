#include <iostream>

using namespace std;

int lotto[49];
int selected[49];

void print_case(int k)
{
	int i;

	for (i = 0; i < k; i++)
	{
		if (selected[i])
		{
			cout << lotto[i] << " ";
		}
	}
	cout << endl;
}

void dfs(int index, int r, int n)
{
	if (index > n)
	{
		return;
	}
	if (r == 6)
	{
		print_case(n);
		return;
	}
	selected[index] = 1;
	dfs(index + 1, r + 1, n);
	selected[index] = 0;
	dfs(index + 1, r, n);
}

int main(void)
{
	int k;
	int i;
	
	while (1)
	{
		cin >> k;
		if (k == 0)
		{
			return 0;
		}	
		if (k <= 6 || k >= 13)
		{
			return -1;
		}
		for (i = 0; i < k; i++)
		{
			cin >> lotto[i];
		}
		dfs(0, 0, k);
		cout << endl;
	}
}
