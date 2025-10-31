#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

ll A, B;
bool isnp[10'000'001];
vector<ll> p;

signed main()
{
    FASTIO;
    cin >> A >> B;

    for(ll i = 2; i<=10'000'000; i++){
        if(isnp[(int)i]) continue;
        p.push_back(i);
        for(ll j = i*i; j<=10'000'000; j+=i) isnp[(int)j] = true;
    }

    ll ans = 0;
    for(ll e: p){
        ll cur = e;
        while(cur <= B/e){
            cur *= e;
            if(A<=cur) ans++;
        }
    }
    
    cout << ans;
    return 0;
}