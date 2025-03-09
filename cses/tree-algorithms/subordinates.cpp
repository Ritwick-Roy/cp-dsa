#include <bits/stdc++.h>
using namespace std;

int func(vector<vector<int> >& a,vector<int>& dp,int i)
{
    if(dp[i]!=-1)
    return dp[i];
    int ans=0;
    for(auto x:a[i])
        ans+=1+func(a,dp,x);
    return dp[i]=ans;
}

void solve()
{
    int n,i,k;
    cin>>n;
    vector<vector<int> > a(n);
    for(i=1;i<n;++i)
    {
        cin>>k;
        a[k-1].push_back(i);
    }
    vector<int> dp(n,-1);
    for(i=0;i<n;++i)
    {
        cout<<func(a,dp,i)<<" ";
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
	return 0;
}