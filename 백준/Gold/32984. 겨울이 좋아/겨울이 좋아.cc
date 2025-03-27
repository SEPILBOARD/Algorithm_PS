#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define ll long long int

int n;
int a[200000];

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++) cin >> a[i];
    for(int i = 0; i<n; i++){
        ll e; cin >> e;
        a[i] = (a[i]+e-1)/e;
    }
    sort(a, a+n);

    ll lo = 0, hi = a[n-1];
    while(lo+1<hi){
        ll mid = lo+hi >> 1;
        ll skill = 0;
        int idx = n-1;
        while(idx>=0 && a[idx]>mid){
            skill += a[idx] - mid;
            if(skill > mid) break;
            idx--;
        }
        // cout << mid <<": " <<skill <<"\n";
        if(skill > mid) lo = mid;
        else hi = mid;
    }
    cout << hi;
    return 0;
}