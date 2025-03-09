#include <bits/stdc++.h>
using namespace std;
#define all(a)         a.begin(),a.end()

typedef long long ll;
typedef vector<ll> vll;

void solve()
{
    ll n,i,j,k,ans=0,x;
    cin>>n>>x;
    ans=n;
    vll a(n);
    for(i=0;i<n;++i)
        cin>>a[i];
    sort(all(a));
    j=upper_bound(all(a),x-a[0])-a.begin();
    i=0;
    while(i<j)
    {
        if(a[i]+a[j]<=x)
        {
            --ans;
            ++i;
        }
        --j;
    }
    cout<<ans<<"\n";
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
	  return 0;
}