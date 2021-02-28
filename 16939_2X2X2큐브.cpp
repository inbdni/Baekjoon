#include <iostream>

using namespace std;

int cube[24];
bool surface[6];

void check()
{
	int i, j, color;
	bool same;

	for (i = 0; i < 6; i++)
	{
		color = cube[4 * i];
		same = true;
		for (j = 1; j < 4; j++)
		{
			if (cube[4 * i + j] != color)
			{
				same = false;
				break;
			}
		}
		surface[i] = same;
	}
}

bool check_color(int sur1, int a, int sur2, int b)
{
	if (cube[sur1 * 4 + a] == cube[sur2 * 4 + b])
		return true;
	return false;
}

bool same_TB()
{
	int i;
	int arr[] = {3, 1, 4, 5};
	bool res;

	res = true;
	for (i = 0; i < 3; i++)
	{
		if (!check_color(arr[i], 0, arr[i], 1) || !check_color(arr[i + 1], 2, arr[i + 1], 3) || !check_color(arr[i], 0, arr[i + 1], 2))
		{
			res = false;
			break;
		}
	}
	if (res)
	{
		return res;
	}
	res = true;
	for (i = 0; i < 3; i++)
	{
		if (!check_color(arr[i], 2, arr[i], 3) || !check_color(arr[i + 1], 0, arr[i + 1], 1) || !check_color(arr[i], 2, arr[i + 1], 0))
		{
			res = false;
			break;
		}
	}
	return res;
}

bool same_FB()
{
	int arr[] = {0, 3, 2, 4};
	bool res;

	res = true;
	if (!check_color(arr[0], 2, arr[0], 3) || !check_color(arr[1], 0, arr[1], 2) || !check_color(arr[0], 2, arr[1], 0))
	{
		res = false;
	}
	else if (!check_color(arr[1], 1, arr[1], 3) || !check_color(arr[2], 2, arr[2], 3) || !check_color(arr[1], 1, arr[2], 2))
	{
		res = false;
	}
	else if (!check_color(arr[2], 0, arr[2], 1) || !check_color(arr[3], 1, arr[3], 3) || !check_color(arr[2], 0, arr[3], 1))
	{
		res = false;
	}
	if (res)	
	{
		return res;
	}
	res = true;
	if (!check_color(arr[0], 0, arr[0], 1) || !check_color(arr[1], 1, arr[1], 3) || !check_color(arr[0], 0, arr[1], 1))
	{
		res = false;
	}
	else if (!check_color(arr[1], 0, arr[1], 2) || !check_color(arr[2], 0, arr[2], 1) || !check_color(arr[1], 0, arr[2], 0))
	{
		res = false;
	}
	else if (!check_color(arr[2], 2, arr[2], 3) || !check_color(arr[3], 0, arr[3], 2) || !check_color(arr[2], 2, arr[3], 0))
	{
		res = false;
	}
	return res;
}

bool same_LR()
{
	int i;
	int arr[] = {0, 1, 2, 5};
	bool res;

	res = true;
	for (i = 0; i < 2; i++)
	{
		if (!check_color(arr[i], 0, arr[i], 2) || !check_color(arr[i + 1], 1, arr[i + 1], 3) || !check_color(arr[i], 0, arr[i + 1], 1))
		{
			res = false;
		}
	}
	if ((!check_color(arr[i], 0, arr[i], 2) || !check_color(arr[i + 1], 0, arr[i + 1], 2) || !check_color(arr[i], 0, arr[i + 1], 0)))
	{
		res = false;
	}
	if (res)	
	{
		return res;
	}
	res = true;
	for (i = 0; i < 2; i++)
	{
		if (!check_color(arr[i], 1, arr[i], 3) || !check_color(arr[i + 1], 0, arr[i + 1], 2) || !check_color(arr[i], 1, arr[i + 1], 0))
		{
			res = false;
		}
	}
	if ((!check_color(arr[i], 1, arr[i], 3) || !check_color(arr[i + 1], 1, arr[i + 1], 3) || !check_color(arr[i], 1, arr[i + 1], 1)))
	{
		res = false;
	}
	return res;
}

int main()
{
	int i;
	bool res = false;

	for (i = 0; i < 24; i++)
	{
		cin >> cube[i];
	}
	check();
	if (surface[0] && surface[2])
	{
		if (same_TB())
		{
			res = true;
		}
	}
	else if (surface[1] && surface[5])
	{
		if (same_FB())
		{
			res = true;
		}
	}
	else if (surface[3] && surface[4])
	{
		if (same_LR())
		{
			res = true;
		}
	}
	cout << res << endl;
	return 0;
}