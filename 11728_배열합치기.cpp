#include <iostream>

using namespace std;

int N;
int M;
int A[1000001];
int B[1000001];

int main()
{
	int a, b;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (a = 0; a < N; a++)
		cin >> A[a];
	for (b = 0; b < M; b++)
		cin >> B[b];
	a = 0;
	b = 0;
	while (a < N && b < M)
	{
		if (A[a] < B[b])
			cout << A[a++] << " ";
		else
			cout << B[b++] << " ";
	}
	while (a < N)
		cout << A[a++] << " ";
	while (b < M)
		cout << B[b++] << " ";
	cout << "\n";
	return 0;
}