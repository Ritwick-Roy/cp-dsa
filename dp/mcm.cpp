#include <bits/stdc++.h> 

int func(vector<vector<int> >& dp,vector<int>& a,int i,int j)
{
    if(i==j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int k,ans=INT_MAX;
    for(k=i;k<j;++k)
        ans=min(ans,func(dp,a,i,k)+func(dp,a,k+1,j)+a[i-1]*a[k]*a[j]);
    return dp[i][j]=ans;
}

int matrixMultiplication(vector<int> &a, int n)
{
    vector<vector<int> > dp(n,vector<int>(n,-1));
    return func(dp,a,1,n-1);
}