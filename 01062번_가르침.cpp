#include <iostream>
#include <string>

using namespace std;

int N;
int K;
int words[50];
int teach;
int answer;

void convert(string &s)
{
	int i, num;
	static int idx = 0;

	for (i = 0; i < s.size(); i++)
	{
		num = s[i] - 'a';
		words[idx] = words[idx] | (0x01 << num);
	}
	idx++;
}

int can_read()
{
	int i, cnt = 0;

	for (i = 0; i < N; i++)
	{
		if ((teach & words[i]) == words[i])
			cnt++;
	}
	return cnt;
}

void dfs(int num, int cnt)
{
	if (cnt == K)
	{
		answer = max(answer, can_read());
		return;
	}
	if (num == 26)
		return;
	teach = teach | (0x01 << num);
	dfs(num + 1, cnt + 1);
	teach = teach & ~(0x01 << num);
	dfs(num + 1, cnt);
}

int main()
{
	string s;
	int i;

	cin >> N >> K;
	for (i = 0; i < N; i++)
	{
		cin >> s;
		convert(s);
	}
	dfs(0, 0);
	cout << answer << endl;
	return 0;
}