#include <bits/stdc++.h> 
using namespace std;
#define ll long long
ll func(vector<vector<ll> >& dp,vector<ll>& a,ll i,ll j)
{
    if(i==j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    ll k,ans=INT_MAX;
    for(k=i;k<j;++k)
        ans=min(ans,func(dp,a,i,k)+func(dp,a,k+1,j)+a[i-1]*a[k]*a[j]);
    return dp[i][j]=ans;
}

ll matrixMultiplication(vector<ll> &a, ll n)
{
    vector<vector<ll> > dp(n,vector<ll>(n,-1));
    return func(dp,a,1,n-1);
}