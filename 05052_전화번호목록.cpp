#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct TRIE
{
	bool finish;
	TRIE *next[10];

	TRIE()
	{
		finish = false;
		memset(next, 0, sizeof(next));
	}

	~TRIE()
	{
		int i;

		for (i = 0; i < 10; i++)
			delete this->next[i];
	}

	void insert(string &s, int idx)
	{
		int curr;

		if (idx == s.size())
		{
			finish = true;
			return;
		}
		curr = s[idx] - '0';
		if (next[curr] == NULL)
			next[curr] = new TRIE();
		next[curr]->insert(s, idx + 1);
	}

	bool find(string &s, int idx)
	{
		int curr;

		if (idx == s.size())
		{
			if (finish)
				return true;
			return false;
		}
		curr = s[idx] - '0';
		if (next[curr] == NULL)
			return false;
		return next[curr]->find(s, idx + 1);
	}
};

int T;
int N;

bool check_consistency(TRIE *node, string s)
{
	int i;
	char c;

	for (i = 0; i < 10; i++)
	{
		if (node->next[i])
		{
			if (node->finish)
				return false;
			c = i + '0';
			if (!check_consistency(node->next[i], s + c))
				return false;
		}
	}
	return true;
}

int main()
{
	int i, j;
	string s;
	TRIE *root;
	bool res;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (i = 0; i < T; i++)
	{
		cin >> N;
		root = new TRIE();
		for (j = 0; j < N; j++)
		{
			cin >> s;
			root->insert(s, 0);
		}
		res = check_consistency(root, "");
		if (res)
			cout << "YES\n";
		else
			cout << "NO\n";
		delete root;
	}
	return 0;
}