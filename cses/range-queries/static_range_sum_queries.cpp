#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,i,j,q;
    cin>>n>>q;
    vector<ll> a(n+1,0);
    cin>>a[1];
    for(i=2;i<=n;++i)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    while(q--)
    {
        cin>>i>>j;
        cout<<a[j]-a[i-1]<<"\n";
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
  	return 0;
}