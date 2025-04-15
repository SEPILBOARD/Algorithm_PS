#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

int n, s;
int psum[100001];

signed main()
{
    FASTIO;
    cin >> n >> s;
    for(int i = 1; i<=n; i++){
        cin >> psum[i];
        psum[i] += psum[i-1];
    }

    int lo = 0, hi = n+1;
    while(lo+1<hi){
        int mid = lo+hi>>1;
        bool flag = false;
        for(int i = mid; i<=n; i++){
            if(psum[i]-psum[i-mid] >= s){
                flag = true;
                break;
            }
        }
        if(flag) hi = mid;
        else lo = mid;
    }
    if(hi == n+1) cout << 0;
    else cout << hi;
    return 0;
}