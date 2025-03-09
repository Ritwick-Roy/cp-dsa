#include <bits/stdc++.h>
using namespace std;
#define all(a)         a.begin(),a.end()
#define multi          ll t;cin>>t;while(t--)
#define in(c,i)        (c.find(i)!=c.end())
#define ff             first
#define ss             second
#define pob            pop_back
#define pof            pop_front
#define pb             push_back
#define pf             push_front
#define sz(x)          (ll)(x.size())
 
typedef long long ll;
 
void solve()
{
    ll n,i,k;
    set<ll> s;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>k;
        s.insert(k);
    }
    cout<<sz(s)<<"\n";
}
 
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
	return 0;
}