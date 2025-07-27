#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;
int a[300'001];

signed main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 0; i<m; i++) cin >> a[i];

    sort(a, a+m);
    
    int lo = 0, hi = a[m-1]+1;
    while(lo+1<hi){
        long long int mid = lo+hi>>1;
        long long int cur_n = m;
        
        for(int i = m-1; i>=0; i--){
            if(a[i] > mid){
                cur_n += (mid-1+a[i])/mid-1;
                if(cur_n>n) break;
            }
        }
        if(cur_n > n) lo = mid;
        else hi = mid;
    }

    cout << hi;
    return 0;
}