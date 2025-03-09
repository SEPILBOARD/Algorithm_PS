#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int
#define double long double

int n; double c;
double t[50];
double x[50];

signed main()
{
    FASTIO;
    cin >> n >> c;
    double lo = -1, hi = 0;
    for(int i = 0; i<n; i++) cin >> t[i];
    for(int i = 0; i<n; i++){
        cin >> x[i];
        x[i] *= t[i];
        hi += x[i];
    }
    while(lo+1<hi){
        double mid = (lo + hi)/2;
        double cur_water = 0;
        bool flag = false;
        for(int i = 0; i<n; i++){
            cur_water += x[i];
            cur_water = max(cur_water - t[i]*mid, (double)0);
            if(cur_water>c){
                flag = true;
                break;
            }
        }
        if(flag) lo = mid;
        else hi = mid;
    }
    if(hi == 0){
        cout << 0;
        return 0;
    }
    double dlo = lo, dhi = hi;
    while(dlo + 0.0000000001 < dhi){
        double mid = (dlo+dhi)/2;
        double cur_water = 0;
        bool flag = false;
        for(int i = 0; i<n; i++){
            cur_water += x[i];
            cur_water = cur_water - t[i]*mid;
            if(cur_water<0) cur_water = 0;
            if(cur_water>c){
                flag = true;
                break;
            }
        }
        if(flag) dlo = mid;
        else dhi = mid;
    }
    cout.precision(11);
    cout << dhi;
    return 0;
}