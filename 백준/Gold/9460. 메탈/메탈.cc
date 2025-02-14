#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

int n, k;
pair<int, int> mt[10000];

void solve()
{
    cin >> n >> k;
    for(int i = 0; i<n; i++){
        int x, y; cin >> x >> y;
        mt[i] = {x, y*10};
    }
    sort(mt, mt+n);

    int lo = -1, hi = 10000000001;
    while(lo+1<hi){
        int mid = (lo+hi)/2;
        int cur_k = 1;
        bool flag = true;
        int mx_y = mt[0].second;
        int mn_y = mt[0].second;
        for(int i = 1; i<n; i++){
            mx_y = max(mx_y, mt[i].second);
            mn_y = min(mn_y, mt[i].second);
            if(mx_y - mn_y > 2*mid){
                cur_k++;
                mx_y = mt[i].second;
                mn_y = mt[i].second;
            }
            if(cur_k>k){
                flag = false;
                break;
            }
        }
        if(flag) hi = mid;
        else lo = mid;
    }
    cout << hi/(double)10 <<"\n";
}

signed main()
{
    FASTIO;
    cout << fixed;
    cout.precision(1);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}