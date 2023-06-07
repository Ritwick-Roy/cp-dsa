#include <bits/stdc++.h>
#define ll long long
using namespace std;

int knapsack(vector<int> &b, vector<int> &a, int n, int w)
{
	vector<vector<int> > dp(n,vector<int>(w+1,0));
	int i,j;
	for(j=a[0];j<=w;++j)
	dp[0][j]=b[0];
	for(i=1;i<n;++i)
	{
		for(j=0;j<=w;++j)
		{
			if(j>=a[i])
			dp[i][j]=max(b[i]+dp[i-1][j-a[i]],dp[i-1][j]);
			else dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n-1][w];
}