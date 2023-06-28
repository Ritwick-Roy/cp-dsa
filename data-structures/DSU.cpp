#include <bits/stdc++.h>
using namespace std;
class DSU{
    vector<int> rank,parent;
  public:
    int count; //stores number of connected components
    DSU(int size)
    {
      rank.resize(size,1);
      parent.resize(size,0);
      count=size;
      for(int i=0;i<size;++i) 
      parent[i]=i;
    }
    int find_set(int x)
    {
      if(parent[x]!=x)
      parent[x]=find_set(x);
      return parent[x];
    }
    void union_set(int x,int y)
    {
      x=find_set(x);
      y=find_set(y);
      if(x!=y)
      {
        if(rank[x]>rank[y])
        {
          parent[y]=x;
        }
        else if(rank[x]<rank[y])
        {
          parent[x]=y;
        }
        else
        {
          parent[y]=x;
          ++rank[x];
        }
        --count;
      }
    }
};

//example
// int findCircleNum(vector<vector<int>>& g)
//     {
//         int n=g.size(),i,j,ans=n;
//         DSU dsu(n);
//         for(i=0;i<n;++i)
//             for(j=i+1;j<n;++j)
//                 if(g[i][j])
//                     dsu.union_set(i,j);
//         return dsu.count;
//     }