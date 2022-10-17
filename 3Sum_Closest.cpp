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



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int a[100];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	sort(a, a + n);
	int target;
	cin >> target;

	int least = INT_MAX;
	int lsum;

	int l = 0;
	int r = n - 1;
	for (int i = 0; i < n - 2; ++i)
	{
		int m = i;
		l = m + 1;
		r = n - 1;
		int st = target - a[m];
		while (l < r)
		{
			int current_diff = abs(target - (a[m] + a[l] + a[r]));

			if (current_diff <= least)
			{
				least = current_diff;
				lsum = (a[m] + a[l] + a[r]);
				// cout << "m:" << m << " l:" << l << " r:" << r << "   " << lsum << endl;
			}
			cout << "m:" << m << "  l:" << l << "  r:" << r << "  -> " << lsum << endl;
			if (a[l] + a[r] < st)
			{
				l++;
			}
			else
			{
				r--;
			}
		}

	}

	cout << least << endl;
	cout << lsum << endl;

	cout << endl;
	cout << endl;

	return 0;
}