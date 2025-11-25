#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int n, k;

signed main()
{
    FASTIO;
    cin >> n >> k;

    int t = 10;
    ll ans = 0;
    for(int i = 1; i<=n; i++){
        if(t<=i)t*=10;
        ans = (ans*t+i)%k;
    }

    cout << ans;
    return 0;
}