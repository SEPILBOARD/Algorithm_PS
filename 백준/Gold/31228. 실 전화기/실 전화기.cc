#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define ll int long long

ll n, k;

ll gcd(ll x, ll y){
    if(y == 0) return x;
    return gcd(y, x%y);
}

int main()
{
    FASTIO;
    cin >> n >> k;

    if(n%k==0){
        cout << "0";
        return 0;
    }
    ll t = gcd(n,k);
    cout << n/t *(min((n-k)/t, k/t)-1);

    return 0;
}