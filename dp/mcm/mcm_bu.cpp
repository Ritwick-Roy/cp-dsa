#include <bits/stdc++.h> 
using namespace std;
ll matrixMultiplication(vector<ll> &a, ll n)
{
    vector<vector<ll> > dp(n+1,vector<ll>(n+1,0));
    ll i,j,k,l,ans;
    for(l=2;l<n;++l)
    {
        for(i=1;l+i-1<=n;++i)
        {
            j=l+i-1;
            ans=INT_MAX;
            for(k=i;k<j;++k)
                ans=min(ans,dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j]);
            dp[i][j]=ans;
        }s
    }
    return dp[1][n-1];
}