#include <bits/stdc++.h>
#define ll long long
using namespace std;

int func(vector<vector<int> >& dp,string& a,string& b,int i,int j)
{
  if(i<0||j<0) return 0;
  if(dp[i][j]!=-1)
  return dp[i][j];
  if(a[i]==b[j])
  return dp[i][j]=1+func(dp,a,b,i-1,j-1);
  return dp[i][j]=max(func(dp,a,b,i-1,j),func(dp,a,b,i,j-1));
}
int lcs(string a, string b)
{
  int i,j,m=a.size(),n=b.size();
  vector<vector<int> > dp(m+1,vector<int>(n+1,0));
  for(i=1;i<=m;++i)
  {
    for(j=1;j<=n;++j)
    {
      if(a[i-1]==b[j-1])
        dp[i][j]=1+dp[i-1][j-1];
      else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
  return dp[m][n];
}