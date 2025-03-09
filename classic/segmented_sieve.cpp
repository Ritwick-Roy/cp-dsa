// C++ code to implement the approach
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

//leetcode

vector<bool> sieve(int limit)
{
    vector<bool> prime(limit + 1, true);
    int p,i;
    for (p=2; p*p<limit; p++)
        if (prime[p] == true)
            for (i=p*p; i<limit; i+=p)
                prime[i] = false;
    return prime;
}

// end leetcode

void simpleSieve(ll limit, vector<ll> &prime)
{
    vector<bool> mark(limit + 1, true);
    ll p,i;
    for (p=2; p*p<limit; p++)
        if (mark[p] == true)
            for (i=p*p; i<limit; i+=p)
                mark[i] = false;
    for (p=2; p<limit; p++)
    {
        if (mark[p])
        {
            prime.push_back(p);
            cout << p << " ";
        }
    }
}

void segmentedSieve(ll n)
{
    ll i,j,limit = floor(sqrt(n))+1,low = limit, high=2*limit;
    vector<ll> prime;
    prime.reserve(limit);
    simpleSieve(limit, prime);
    while (low < n)
    {
        if (high >= n)
           high = n;
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
        for(i = 0; i < prime.size(); i++)
        {
            ll loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
            for (j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }
 
        for (i = low; i<high; i++)
            if (mark[i - low])
                cout << i << " ";
        low+=limit;
        high+=limit;
    }
}
 
int main()
{
    ll n = 1e12;
    cout << "Primes smaller than " << n << ":\n";
    segmentedSieve(n);
    return 0;
}
