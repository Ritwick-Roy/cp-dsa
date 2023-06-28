#include <bits/stdc++.h>
using namespace std;
#define ll long long
class MEX {
public:
    map<ll, ll> frequency;
    set<ll> missing_numbers;
    vector<ll> a;

    MEX(vector<ll> const& a) : a(a)
    {
        for (ll i = 0; i <= a.size(); i++)
            missing_numbers.insert(i);

        for (ll x : a)
        {
            ++frequency[x];
            missing_numbers.erase(x);
        }
    }

    ll mex()
    {
        return *missing_numbers.begin();
    }

    void update(ll idx, ll new_value)
    {
        if (--frequency[a[idx]] == 0)
            missing_numbers.insert(a[idx]);
        a[idx] = new_value;
        ++frequency[new_value];
        missing_numbers.erase(new_value);
    }
};
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll> a{5,2,1,4,5,2,6,7,9,0};
    MEX t(a);
    cout<<t.mex()<<"\n";
    t.update(3,3);
    cout<<t.mex()<<"\n";
    t.update(0,4);
    cout<<t.mex()<<"\n";
	return 0;
}
