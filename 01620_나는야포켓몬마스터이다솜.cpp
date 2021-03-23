#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int N, M;
vector<string> dict1;
unordered_map<string, int> dict2;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i;
	string s;

	cin >> N >> M;
	dict1.resize(N + 1);
	for (i = 1; i <= N; i++)
	{
		cin >> s;
		dict1[i] = s;
		dict2[s] = i;
	}
	for (i = 0; i < M; i++)
	{
		cin >> s;
		if (isdigit(s[0]))
			cout << dict1[stoi(s)] << "\n";
		else
			cout << dict2[s] << "\n";
	}
	return 0;
}