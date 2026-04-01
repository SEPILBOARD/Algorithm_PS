#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;
int a[100'005];

ll dist(ll x)
{
    ll ret = 0;
    for(int i = 1; i<n; i++){
        ret += abs(x*i-a[i]);
    }
    return ret;
}

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++) cin >> a[i];

    ll lo = 0, hi = 1e+9;
    while(hi-lo>3){
        ll l = (lo+lo+hi)/3;
        ll r = (hi+hi+lo)/3;
        
        if(dist(l)<dist(r)) hi = r;
        else lo = l;
    }

    ll ans = 1e+18;
    for(ll i = lo; i<=hi; i++){
        ans = min(ans, dist(i));
    }
    cout << ans;

    return 0;
}