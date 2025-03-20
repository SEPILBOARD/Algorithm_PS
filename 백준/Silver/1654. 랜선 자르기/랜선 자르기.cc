#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

int k, n;
int len[10000];

signed main()
{
    FASTIO;
    cin >> k >> n;
    for(int i = 0; i<k; i++) cin >> len[i];

    int lo = 0, hi = 10000000007;
    while(lo+1<hi){
        int mid = lo+hi >> 1;
        int cnt = 0;
        for(int i = 0; i<k; i++){
            cnt += len[i]/mid;
        }
        if(cnt >= n) lo = mid;
        else hi = mid;
    }
    cout << lo;
    return 0;
}