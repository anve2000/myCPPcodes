#include<iostream>
#include<cmath>
#include<climits>
#include<cstring>

using namespace std;

int Knapsack_Top_Down(int dp[][100], int *price, int *weight, int capacity, int n)
{
	///base
	if (n == 0 || capacity == 0)
		return dp[n][capacity] = 0;

	if (dp[n][capacity] != -1)
		return dp[n][capacity];
	//rec
	int op1 = INT_MIN, op2 = INT_MIN;
	if (capacity >= weight[n - 1])
		op1 = price[n - 1] + Knapsack_Top_Down(dp, price, weight, capacity - weight[n - 1], n);

	op2 = Knapsack_Top_Down(dp, price, weight, capacity, n - 1);

	return dp[n][capacity] = max(op1, op2);
}

int Knapsack_Bottom_Up(int *price, int* weight, int capacity, int n)
{
	int dp[100][100] = {0};
	// for (int i = 0; i <= n; ++i)
	// {
	// 	dp[i][0] = 0;
	// }

	// for (int i = 0 ; i <= capacity; ++i)
	// {
	// 	dp[0][i] = 0;
	// }

	for (int i = 1; i <= n; ++i)
	{
		int op1 = INT_MIN, op2 = INT_MIN;
		for (int j = 1; j <= capacity; ++j)
		{
			if (j >= weight[i - 1])
				op1 = price[i - 1] + dp[i - 1][j - weight[i - 1]];

			op2 = 0 + dp[i - 1][j];

			dp[i][j] = max(op1, op2);
		}
	}

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= capacity; ++j)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	return dp[n][capacity];

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int price[100];
	int weight[100];
	int dp[100][100];
	memset(dp, -1, sizeof(dp));

	int n ;
	cin >> n;

	int cap;
	cin >> cap;
	for (int i = 0; i < n; ++i)
	{
		cin >> weight[i];
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> price[i];
	}

	// int capacity = 5;
	cout << Knapsack_Top_Down(dp, price, weight, cap, n);
	// Knapsack_Bottom_Up(price, weight, cap, n);

	cout << endl;
	return 0;
}