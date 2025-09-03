#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

ll n, m;
ll a[300'001];
ll b[300'001];

signed main()
{
    FASTIO;
    cin >> n >> m;
    ll mx = 0;
    for(int i = 0; i<n; i++) cin >> a[i];
    for(int i = 0; i<n; i++){
        cin >> b[i];
        a[i] = max(a[i], b[i]);
        mx = max(a[i], mx);
    }



    ll lo = 0;
    ll hi = mx*m+1ll;
    while(lo+1<hi){
        ll mid = lo+hi>>1;
        ll cnt = 0ll;

        // cout << mid <<":\n";

        for(int i = 0; i<n; i++){
            if(mid <= a[i]*m){
                cnt += (mid+a[i]-1ll)/a[i];
                // cout << i <<": ";
            }
            else{
                cnt += ((mid-a[i]*m)+b[i]-1ll)/b[i] + m;
            }
            // cout << cnt <<", ";
            if(cnt > n*m) break;
        }
        // cout << "\n";

        if(n*m>=cnt) lo = mid;
        else hi = mid;
    }
    cout << lo;
    return 0;
}