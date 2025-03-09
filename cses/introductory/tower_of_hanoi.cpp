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

void solve(ll i,ll from,ll to,ll aux)
{
    if(i==0)
        return;
    solve(i-1,from,aux,to);
    cout<<from<<" "<<to<<"\n";
    solve(i-1,aux,to,from);
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    cout<<pow(2,n)-1<<"\n";
    solve(n,1,3,2);
	return 0;
}