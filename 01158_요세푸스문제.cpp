#include <iostream>
#include <vector>

using namespace std;

int N;
int K;
vector<int> list;
vector<int> answer;

void init()
{
	int i;

	for (i = 1; i <= N; i++)
		list.push_back(i);
}

void josephus()
{
	int i = 0;
	int k = 1;

	while (!list.empty())
	{
		if (i == list.size())
		{
			i = 0;
		}
		if (k == K)
		{
			k = 1;
			answer.push_back(list[i]);
			list.erase(list.begin() + i);
		}
		else
		{
			i++;
			k++;
		}
	}
}

void print_per()
{
	int i;

	cout << "<";
	for (i = 0; i < answer.size() - 1; i++)
	{
		cout << answer[i] << ", ";
	}
	cout << answer[i] << ">" << endl;
}

int main()
{
	cin >> N >> K;
	init();
	josephus();
	print_per();
	return 0;
}