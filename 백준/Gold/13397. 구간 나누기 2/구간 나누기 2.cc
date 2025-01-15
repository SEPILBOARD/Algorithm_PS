#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;
int a[5000];

int main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    int lo = -1, hi = 10001;
    while(lo+1 < hi){
        int mid = (lo+hi)/2;
        int cur_div = 1, cur_max = a[0], cur_min = a[0];
        bool flag = true;
        for(int i = 1; i<n; i++){
            cur_max = max(cur_max, a[i]);
            cur_min = min(cur_min, a[i]);
            if(cur_max-cur_min > mid){
                cur_div++;
                cur_max = a[i]; cur_min = a[i];
            }
            if(cur_div > m){
                flag = false;
                break;
            }
        }
        if(flag) hi = mid;
        else lo = mid;
    }
    cout << hi;
    return 0;
}