#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;
int coin[21];
int dp[10'001];

void solve()
{
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for(int i = 0; i<n; i++) cin >> coin[i];
    cin >> m;

    dp[0] = 1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j+coin[i]<=m; j++){
            dp[j+coin[i]] += dp[j];
        }
    }
    cout << dp[m] <<"\n";
}

signed main()
{
    FASTIO;
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}