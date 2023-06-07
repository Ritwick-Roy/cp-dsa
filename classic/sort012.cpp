#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void sortColors(vector<ll>& a)
{
  ll lo=0,hi=a.size()-1,m=0;
  while(m<=hi)
  {
    if(a[m]==2)
      swap(a[m],a[hi--]);
    else if(a[m]==0)
    {
      swap(a[m],a[lo++]);
      ++m;
    }
    else ++m;
  }
}