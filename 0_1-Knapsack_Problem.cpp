#include<iostream>
#include<cmath>
#include<climits>
#include<cstring>

using namespace std;

int Knapsack_Top_Down(int *dp, int *price, int *weight, int capacity, int n)
{
	///base
	if (n == 0 or capacity == 0)
		return dp[n] = 0;
	//rec
	int op1 = INT_MIN, op2 = INT_MIN;
	if (capacity >= weight[n - 1])
		op1 = price[n - 1] + Knapsack_Top_Down(dp, price, weight, capacity - weight[n - 1], n - 1);

	op2 = Knapsack_Top_Down(dp, price, weight, capacity, n - 1);

	return dp[n] = max(op1, op2);
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

	int price[] = {4, 5, 8, 1};
	int weight[] = {1, 3, 5, 1};
	int dp[100];
	memset(dp, -1, sizeof(dp));

	int n = sizeof(weight) / sizeof(int);

	int capacity = 5;
	// cout << Knapsack_Top_Down(dp, price, weight, capacity, n);
	Knapsack_Bottom_Up(price, weight, capacity, n);

	cout << endl;
	return 0;
}