#include <bits/stdc++.h>
#define ll long long
using namespace std;

int lengthOfLIS(vector<int>& a)
{
  vector<int> t;
  for(auto x:a)
  {
    if(t.empty()||x>t.back())
    t.push_back(x);
    else
    {
      auto it=lower_bound(t.begin(),t.end(),x);
      *it=x;
    }
  }
  return t.size();    
}