#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

int l, k, c;
int tnm[10001];

signed main()
{
    FASTIO;
    cin >> l >> k >> c;
    for(int i = 0; i<k; i++) cin >> tnm[i];
    tnm[k] = l;
    sort(tnm, tnm+k+1);

    int lo = 0, hi = l+1;
    while(lo+1 < hi){
        int mid = lo+hi>>1;
        if(tnm[0]>mid){
            lo = mid;
            continue;
        }
        int s = 0;
        int cur_cut = 0;
        for(int i = 1; i<=k; i++){
            if(tnm[i]-s > mid){
                cur_cut++;
                s = tnm[i-1];
                if(tnm[i]-tnm[i-1] > mid) cur_cut = c+1;
            }
            if(cur_cut>c) break;
        }
        if(cur_cut>c) lo = mid;
        else hi = mid;
    }
    cout << hi;

    int lo2 = -1, hi2 = k;
    while(lo2+1 < hi2){
        int mid = lo2+hi2>>1;
        if(tnm[mid]>hi){
            hi2 = mid;
            continue;
        }
        int s = tnm[mid];
        int cur_cut = 1;
        for(int i = mid+1; i<=k; i++){
            if(tnm[i]-s > hi){
                cur_cut++;
                s = tnm[i-1];
            }
            if(cur_cut>c){
                break;
            }
        }
        if(cur_cut>c) lo2 = mid;
        else hi2 = mid;
    }
    cout << " " <<tnm[hi2];

    return 0;
}