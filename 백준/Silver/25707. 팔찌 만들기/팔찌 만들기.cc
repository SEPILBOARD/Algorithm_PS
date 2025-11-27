#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;
ll a[1001];

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    sort(a, a+n);

    ll ans = 0;
    for(int i = 1; i<n; i++){
        ans += a[i]-a[i-1];
    }
    ans += a[n-1]-a[0];

    cout << ans;
    return 0;
}   