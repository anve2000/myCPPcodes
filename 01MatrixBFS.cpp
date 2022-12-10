#include<iostream>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<cstring>//<--strings
#include<algorithm>//<--sort
#include<unordered_map>
#include<map>
#include<list>
#include<cstring>

using namespace std;

#define ll long long int
#define pb push_back
#define mp make_pair

class Solution {
public:

	void solve(vector<vector<int>>& mat, queue<pair<int, int> >q)
	{
		vector<vector<bool>>vis;
		while (!q.empty())
		{
			auto x = q.front();
			int a = x.first, b = x.second;
			if (a + 1 < )
			}
	}

	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
		queue<pair<int, int> >q;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (mat[i][j] == 0)
				{
					q.push({i, j});
					// solve(mat, q);
				}
				else
				{
					mat[i][j] = -1;
				}
			}
		}

		while (!q.empty())
		{
			auto x = q.front();
			int a = x.first, b = x.second;
			q.pop();
			if (a + 1 < n and mat[a + 1][b] == -1)
			{
				mat[a + 1][b] = mat[a][b] + 1;
				q.push({a + 1, b});
			}

			if (b + 1 < m and mat[a][b + 1] == -1)
			{
				mat[a][b + 1] = mat[a][b] + 1;
				q.push({a, b + 1});
			}

			if (a > 0 and mat[a - 1][b] == -1)
			{
				mat[a - 1][b] = mat[a][b] + 1;
				q.push({a - 1, b});
			}

			if (b > 0 and mat[a][b - 1] == -1)
			{
				mat[a][b - 1] = mat[a][b] + 1;
				q.push({a, b - 1});
			}
		}

		return mat;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif



	cout << endl;
	cout << endl;

	return 0;
}