#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;
bool chk[5'001];
ll a[5'001];

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> a[i];

    ll lo = 0ll, hi = (n-1)*(1ll+abs(a[n]-a[1]))+1ll;
    while(lo+1<hi){
        ll mid = lo+hi >> 1;

        memset(chk, false, sizeof(bool)*(n+1));
        chk[1] = true;
        for(int i = 1; i<=n; i++){
            if(!chk[i]) continue;
            for(int j = i+1; j<=n; j++){
                ll f = (j-i)*(1ll+abs(a[j]-a[i]));
                if(f>mid) continue;
                chk[j] = true;
                if(j == n) break;
            }
            if(chk[n]) break;
        }

        if(chk[n]) hi = mid;
        else lo = mid;
    }

    cout << hi;
    return 0;
}