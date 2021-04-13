#include <iostream>

using namespace std;

int N;
int mem[1000001];

int solution()
{
	int num;

	mem[1] = 0;
	for (num = 2; num <= N; num++)
	{
		mem[num] = mem[num - 1] + 1;
		if (num % 2 == 0)
			mem[num] = min(mem[num], mem[num / 2] + 1);
		if (num % 3 == 0)
			mem[num] = min(mem[num], mem[num / 3] + 1);
	}
	return mem[N];
}

int main()
{
	cin >> N;
	cout << solution() << endl;
	return 0;
}