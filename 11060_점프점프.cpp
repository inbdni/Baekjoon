#include <iostream>

using namespace std;

int N;
int maze[1001];
int jump[1001];

int main()
{
	int i;
	int j;
    
	cin >> N;
	if (N < 1 || N > 1000)
	{
		return -1;
	}
	for (i = 1; i <= N; i++)
	{
		cin >> maze[i];
	}
	jump[1] = 1;
    for (i = 1; i <= N; i++)
	{
        if (jump[i] == 0)
            continue;
        for (j = 1; j <= maze[i]; j++)
		{
			if (i + j > N)
				break;
            if (jump[i + j] == 0 || jump[i + j] > jump[i] + 1)
                jump[i + j] = jump[i] + 1;
        }        
    }
    if(jump[N])
		cout << jump[N] - 1 << endl;
	else
        cout << -1 << endl;
	return 0;
}