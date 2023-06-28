#include <bits/stdc++.h>
using namespace std;
#define all(a)         a.begin(),a.end()
#define multi          ll t;cin>>t;while(t--)
#define in(c,i)      (c.find(i)!=c.end())
#define ff             first
#define ss             second
#define pob            pop_back
#define pof            pop_front
#define pb             push_back
#define pf             push_front
#define sz(x)          (ll)(x.size())

typedef long long ll;
typedef vector<ll> vll;

const long long MAX_SIZE = 1e7;
 
// isPrime[] : isPrime[i] is true if number is prime
// prime[] : stores all prime number less than N
// SPF[] that store smallest prime factor of number
// [for Exp : smallest prime factor of '8' and '16'
// is '2' so we put SPF[8] = 2 , SPF[16] = 2 ]
vector<bool> isprime(MAX_SIZE , true);
vll prime;
 
vll sieve(ll n=MAX_SIZE)
{
    isprime[0] = isprime[1] = false;
    vll spf(n);
    ll i,j;
    for(i=2;i<n;++i)
    {
        if(isprime[i])
        {
            prime.push_back(i);
            spf[i] = i;
        }
        for(j=0;j<prime.size() && i*prime[j] < n && prime[j] <= spf[i];++j)
        {
            isprime[i*prime[j]]=false;
            spf[i*prime[j]] = prime[j];
        }
    }
    return spf;
}
 
vll factorize(ll x,vector<ll>& spf)
{
	vll ret;
	while (x != 1)
    {
		ret.push_back(spf[x]);
		x = x / spf[x];
	}
	return ret;
}

int main()
{
	// precalculating Smallest Prime Factor
	vll spf=sieve();
	vector<ll> p = factorize(8147514,spf);
	for (ll x:p)
		cout << x << " ";
    cout<<"\n";
    for(auto x:prime)
    cout<<x<<" ";

    // for counting prime numbers in ranges
    vll prefix(MAX_SIZE,0);
    for(ll i=2;i<MAX_SIZE;++i)
        prefix[i]=prefix[i-1]+(spf[i]==i);

    // cout<<prefix[R]-prefix[L-1];

	return 0;
}
