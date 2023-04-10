#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll start=-1,ce=-1;

bool dfs(vector<vector<ll> >& g,vector<ll>& vis,vector<ll>& parent,ll node)
{
  vis[node]=1;

  for(auto& v:g[node])
  {
    if(v==parent[node]) continue;
    if(vis[v])
    {
      start=v;
      ce=node;
      return true;
    }
    parent[v]=node;
    if(dfs(g,vis,parent,v))
    return true;
  }
    return false;
}

void solve()
{
  ll u,v,n,m,i,node;
  cin>>n>>m;
  vector<ll> parent(n,-1),vis(n,0);
  vector<vector<ll> > g(n);
  for(i=0;i<m;i++)
  {
    cin>>u>>v;
    g[u-1].push_back(v-1);
    g[v-1].push_back(u-1);
  }

  for(i=0;i<n;++i)
    if(!vis[i] && dfs(g,vis,parent,i))
      break;

  if(start==-1) cout<<"IMPOSSIBLE\n";
  else
  {
    vector<ll> path;
    path.push_back(start);
    for(node=ce;node!=start;node=parent[node])
    path.push_back(node);
    path.push_back(start);
    cout<<path.size()<<"\n";
    for(auto& x:path)
    cout<<x+1<<" ";  
  }
}

int main() 
{
  solve();
  return 0;
}
