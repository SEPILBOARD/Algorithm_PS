#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

ll x, y, z;

signed main()
{
    FASTIO;
    cin >> x >> y;
    
    z = 100LL*y/x;
    if(z>=99){
        cout << "-1";
        return 0;
    }
    ll lo = 0, hi = x;
    while(lo+1<hi){
        ll mid = lo+hi>>1;
        if(z != 100LL*(y+mid)/(x+mid)){
            hi = mid;
        }
        else{
            lo = mid;
        }
    }
    cout << hi;
    return 0;
}