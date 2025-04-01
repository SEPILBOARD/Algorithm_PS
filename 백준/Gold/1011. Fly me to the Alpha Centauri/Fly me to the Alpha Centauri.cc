#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

void solve()
{
    int x, y; cin >>  x >> y;
    y -= x-1;
    if(y == 2){
        cout << "1\n";
        return;
    }
    int lo = 0, hi = 70000;
    while(lo+1<hi){
        int mid = lo+hi >> 1;
        if(mid*(mid+1)+2 <= y) lo = mid;
        else hi = mid;
    }
    int ans = lo*2;
    y -= lo*(lo+1)+2;
    if(y <= lo) ans+=1;
    else ans+=2;
    // cout << y <<"\n";
    cout << ans <<"\n";
}

signed main()
{
    FASTIO;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}