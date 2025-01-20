#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

int n, m;
int lvl[100000];
int item[100000];
int maxlvl[100000];
int mxl = 0;

signed main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        cin >> lvl[i];
        mxl = max(mxl, lvl[i]);
    }
    for(int i = 0; i<n; i++){
        cin >> item[i];
    }
    
    for(int i = 0; i<n; i++){
        int lo = lvl[i]; int hi = 2000001003;
        while(lo+1 <hi){
            int mid = (lo + hi)/2;
            int tp = (mid-lvl[i])*(lvl[i] + mid-1)/2;
            if(tp>item[i]) hi = mid;
            else lo = mid;
        }
        maxlvl[i] = lo;
    }

    int lo = mxl-1; int hi = 2000001003+m/n;
    while(lo+1 < hi){
        int mid = (lo + hi)/2;
        int ssb = m;
        // cout << "#" << mid << "\n";
        for(int i = 0; i<n; i++){
            if(maxlvl[i] >= mid) continue;
            ssb -= mid - maxlvl[i];
            if(ssb < 0) break;
        }
        if(ssb < 0) hi = mid;
        else lo = mid;
    }
    if(lo < mxl) cout << -1;
    else cout <<  lo;
    return 0;
}