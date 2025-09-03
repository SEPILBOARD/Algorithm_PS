#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

ll n, m;
int a[300'001];
int b[300'001];

signed main()
{
    FASTIO;
    cin >> n >> m;
    int mx = 0;
    for(int i = 0; i<n; i++) cin >> a[i];
    for(int i = 0; i<n; i++){
        cin >> b[i];
        a[i] = max(a[i], b[i]);
        mx = max(a[i], mx);
    }



    ll lo = 0, hi = mx*m+1;
    while(lo+1<hi){
        ll mid = lo+hi>>1;
        ll cnt = 0ll;

        // cout << mid <<":\n";

        for(int i = 0; i<n; i++){
            if(mid <= (ll)a[i]*m){
                cnt += (mid+a[i]-1)/a[i];
                // cout << i <<": ";
            }
            else{
                cnt += ((mid-(ll)a[i]*m)+b[i]-1)/b[i] + m;
            }
            // cout << cnt <<", ";
        }
        // cout << "\n";

        if(n*m>=cnt) lo = mid;
        else hi = mid;
    }
    cout << lo;
    return 0;
}