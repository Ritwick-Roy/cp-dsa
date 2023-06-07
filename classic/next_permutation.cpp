#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void nextPermutation(vector<ll>& a)
    {
        ll pos=-1,n=a.size(),i;
        for(i=n-2;i>=0;--i)
        {
            if(a[i]<a[i+1])
            {
                pos=i;
                break;
            }
        }
        if(pos==-1)
        {
            reverse(a.begin(),a.end());
            return;
        }
        for(i=n-1;i>pos;--i)
        {
            if(a[i]>a[pos])
            {
                swap(a[i],a[pos]);
                break;
            }
        }
        reverse(a.begin()+pos+1,a.end());
    }