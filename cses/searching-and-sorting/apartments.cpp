#include <bits/stdc++.h>
using namespace std;
#define all(a)         a.begin(),a.end()

typedef long long ll;
typedef vector<ll> vll;

void solve()
{
    ll n,i,j,k,m,ans=0;
    cin>>n>>m>>k;
    vll a(n),b(m);
    for(i=0;i<n;++i)
        cin>>a[i];
    for(i=0;i<m;++i)
        cin>>b[i];
    sort(all(a));
    sort(all(b));
    i=j=0;
    while(i<n && j<m)
    {
        if(a[i]+k>=b[j] && b[j]>=a[i]-k)
        {
            ++ans;
            ++i;
            ++j;
        }
        else if(a[i]-k>b[j])
        {
            ++j;
        }
        else ++i;
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