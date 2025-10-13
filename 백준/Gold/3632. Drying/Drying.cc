#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;
#define int long long int

int n, k;

signed main()
{
    FASTIO;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin >> a[i];
    cin >> k;

    if(k == 1){
        int ma = 0;
        for(int i = 0; i<n; i++){
            ma = max(ma, a[i]);
        }
        cout << ma;
        return 0;
    }

    sort(a.begin(), a.end());

    ll lo = 0, hi = 1e+9+1;
    while(lo+1<hi){
        ll mid = lo+hi>>1;

        int cur = 0;
        bool flag = true;
        for(int i = n-1; i>=0; i--){
            if(a[i]>mid){
                cur += (a[i]-mid+k-2)/(k-1);
                if(cur > mid){
                    flag = false;
                    break;
                }
            }
        }

        if(flag) hi = mid;
        else lo = mid;
    }

    cout << hi;

    return 0;
}