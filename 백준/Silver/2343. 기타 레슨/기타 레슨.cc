#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int n, m;
int lec[100000];

signed main()
{
    FASTIO;
    cin >> n >> m;
    ll lo = 0, hi = 1;
    for(int i = 0; i<n; i++){
        cin >> lec[i];
        hi += lec[i];
    }
    while(lo+1 < hi){
        ll mid = lo+hi >>1;
        int cur_len = 0;
        int cur_cut = 1;
        for(int i = 0; i<n; i++){
            if(lec[i]>mid){
                cur_cut = m+1;
                break;
            }
            cur_len += lec[i];
            if(cur_len > mid){
                cur_cut ++;
                cur_len = lec[i];
                if(cur_cut > m) break;
            }
        }
        if(cur_cut > m) lo = mid;
        else hi = mid;
    }
    cout << hi;
    return 0;
}