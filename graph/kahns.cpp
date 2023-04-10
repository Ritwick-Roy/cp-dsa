#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define tr(c,it) for(typeof(c.begin()) it=c.begin();it!=c.end();it++)
#define multi ll t;cin>>t;while(t--)
#define present(c,i) (c.find(i)!=c.end())
#define cpresent(c,i) (find(all(c),i)!=c.end())
#define mod 1000000007


bool kahns(int n,vector<vector<int>>& edges)  // or vector<vector<int> > g
{
  int i,c=0;
  vector<vector<int> > g(n);
  vector<int> indeg(n,0);
  for(auto& x:edges)
  {
    g[x[0]].push_back(x[1]);
    indeg[x[1]]++;
  }
  queue<int> q;
  for(i=0;i<n;++i)
  {
    if(indeg[i]==0)
    q.push(i);
  }
  while(!q.empty())
  {
    ++c;
    int u=q.front();
    q.pop();
    cout<<u<<" ";
    for(auto v:g[u])
    {
      indeg[v]--;
      if(indeg[v]==0)
      q.push(v);
    }
  }
  return c<n; // returns if loop is present and prints topological ordering
}

void solve()
{
    ll n,i,j,k,m;
    vector<ll> a;
    cin>>n;
    for(i=0;i<n;i++)
    { cin>>k; a.pb(k); }
    
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    multi 
    solve();
	return 0;
}
