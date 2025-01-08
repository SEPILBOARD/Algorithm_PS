#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
long long int k;
long long int a[100000];
long long int sorted_a[100000];
long long int ans;

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        sorted_a[i] = a[i];
    }
    cin >> k;
    if(n == 1){
        cout << k;
        return 0;
    }
    sort(sorted_a, sorted_a + n);
    long long int pidx = 0;
    for(int i = n-1; i>0; i--){
        if(sorted_a[i] != a[i]){
            pidx = i;
            break;
        }
    }
    long long int cur_max = sorted_a[pidx];
    long long int pb = 0;
    if(pidx != 0)
    {
        for(int i = 0; i<=pidx; i++){
            pb += sorted_a[pidx] - a[i];
        }
        if(pb > k){
            cout << 0;
            return 0;
        }
        ans ++;
        k -=pb;
    }

    while(pidx <n-1){
        long long int nidx = pidx+1;
        while(a[nidx] == a[nidx+1]) nidx ++;
        long long int sd = (a[nidx] - cur_max) * (pidx +1);
        if(k<sd){
            ans += k/(pidx+1);
            cout << ans;
            return 0;
        }
        ans += a[nidx] - cur_max;
        pidx = nidx;
        cur_max = a[pidx];
        k -= sd;
    }
    ans += k/(long long int)n;
    cout << ans;
    return 0;
}