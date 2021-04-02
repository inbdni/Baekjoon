#include <iostream>
#include <string>
#include <vector>

using namespace std;

string T;
string P;
int fail[1000001];
vector<int> res;

void failure()
{
	int i, j = 0;

	for (i = 1; i < P.size(); i++)
	{
		while (j > 0 && P[i] != P[j])
			j = fail[j - 1];
		if (P[i] == P[j])
			fail[i] = ++j;
	}
}

void kmp()
{
	int i, j = 0;

	for (i = 0; i < T.size(); i++)
	{
		while (j > 0 && T[i] != P[j])
			j = fail[j - 1];
		if (T[i] == P[j])
		{
			j++;
			if (j == P.size())
			{
				j = fail[j - 1];
				res.push_back(i - P.size() + 2);
			}
		}
	}
}

void print_answer()
{
	int i;

	cout << res.size() << endl;
	for (i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
}

int main()
{
	getline(cin, T);
	getline(cin, P);
	failure();
	kmp();
	print_answer();
	return 0;
}