#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int
int n;

signed main()
{
    FASTIO;
    cin >> n;
    int lo = 0, hi = 25000;
    while(lo+1 < hi){
        int mid = lo+hi >> 1;
        if(mid * (mid+1)/2 <n) lo = mid;
        else hi = mid;
    }
    int itv = (hi*(hi+1)/2) - n;
    if(hi%2) cout << itv+1 << "/" <<hi-itv;
    else cout << hi - itv << "/" <<itv+1;
    return 0;
}