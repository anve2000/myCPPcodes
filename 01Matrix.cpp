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


// class Solution {
// public:



int m, n;

void print(vector<vector<int>>& mat)
{
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << mat[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl;
}

vector<vector<bool>> vis;
void redesign(vector<vector<int>>& mat, int i, int j, int step)
{

	if (i >= n || j >= m || i < 0 || j < 0 || vis[i][j] == true || mat[i][j] == 0 ||  (mat[i][j] <= step and mat[i][j] != 1))
		return;


	cout << " mat[" << i << "][" << j << "]   : " << mat[i][j] << "  with steps :" << step << endl;

	if ((mat[i][j] > step || mat[i][j] == 1))
	{
		mat[i][j] = step - 1;
	}

	// mat[i][j] = 0;
	vis[i][j] = true;
	// cout << i << "  " << j << "  " << step << endl;
	redesign(mat, i + 1, j, step + 1);
	redesign(mat, i - 1, j, step + 1);
	redesign(mat, i, j + 1, step + 1);
	redesign(mat, i, j - 1, step + 1);
	vis[i][j] = false;
}

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
	m = mat[0].size();
	n = mat.size();

	vis.resize(n, vector<bool>(m));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (mat[i][j] == 0)
			{
				// vis[i][j] = 1;
				mat[i][j] = 1;
				redesign(mat, i, j, 1);
				vis[i][j] = 0;
				mat[i][j] = 0;
			}
			print(mat);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (mat[i][j] > 1)
			{
				mat[i][j] -= 1;
			}
		}
	}

	print(mat);


}
// };


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// int m,n;
	cin >> m >> n;

	// cout << "hello" << endl;

	vector<vector<int > >mat(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> mat[i][j];
		}
	}

	updateMatrix(mat);

	cout << endl;
	cout << endl;

	return 0;
}