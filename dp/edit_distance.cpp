#include <bits/stdc++.h>
#define ll long long
using namespace std;

int minDistance(string a, string b)
{
  int i,j,m=a.size(),n=b.size();
  vector<vector<int> > dp(m+1,vector<int>(n+1,0));
  if(m==0) return n;
  if(n==0) return m;
  for(j=0;j<=n;++j)
    dp[0][j]=j;
  for(i=0;i<=m;++i)
    dp[i][0]=i;
  for(i=1;i<=m;++i)
  {
    for(j=1;j<=n;++j)
    {
      if(a[i-1]==b[j-1])
        dp[i][j]=dp[i-1][j-1];
      else
        dp[i][j]=1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
    }
  }
  return dp[m][n];
}