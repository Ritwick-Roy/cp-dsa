#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,i,j,ans=1;
    cin>>n;
    vector<pair<ll,ll> > a(n);
    for(i=0;i<n;++i)
        cin>>a[i].second>>a[i].first;
    sort(a.begin(),a.end());
    j=a[0].first;
    for(i=1;i<n;++i)
    {
        if(a[i].second>=j)
        {
            ++ans;
            j=a[i].first;
        }
    }
    cout<<ans<<"\n";
	return 0;
}