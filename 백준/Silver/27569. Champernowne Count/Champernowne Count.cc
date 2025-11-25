#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int n, k;

signed main()
{
    FASTIO;
    cin >> n >> k;

    ll cur = 0;
    int ans = 0;
    int t = 10;
    for(int i = 1; i<=n; i++){
        if(t<=i) t *= 10;
        cur = (cur*t+i)%k;
        if(cur == 0) ans++;
    }

    cout << ans;
    return 0;
}