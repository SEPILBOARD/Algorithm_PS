#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, b, a;
int cost[100'001];

signed main()
{
    FASTIO;
    cin >> n >> b >> a;
    for(int i = 1; i<=n; i++) cin >> cost[i];

    sort(cost+1, cost+n+1);

    int lo = 0, hi = n+1;
    while(lo+1<hi){
        int mid = hi+lo>>1;
        long long int sum = 0;
        int hidx = max(1, mid-a+1);
        for(int i = mid; i>=hidx; i--) sum += cost[i]/2;
        for(int i = 1; i<hidx; i++) sum += cost[i];
        if(sum > b) hi = mid;
        else lo = mid;
    }
    cout << lo;
    return 0;
}