#include <iostream>
#include <cstring>

using namespace std;

int N;
int K;
int num[200001];
int cnt[100001];

int main()
{
	int i, s, e;
	int res = 0;
	bool flag;
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	s = 1;
	e = 1;
	while (s <= e && e <= N)
	{
		while (e <= N)
		{
			if (cnt[num[e]] == K)
				break;
			cnt[num[e++]]++;
		}
		res = max(res, e - s);
		flag = true;
		while (s < e && flag)
		{
			if (cnt[num[s]] == K)
				flag = false;
			cnt[num[s++]]--;
		}
	}
	cout << res << "\n";
	return 0;
}