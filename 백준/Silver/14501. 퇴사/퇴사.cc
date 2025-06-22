#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
pair<int, int> tp[17];

int dp[17];

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 1; i<=n; i++){
        int t, p; cin >> t >> p;
        tp[i] = {t, p};
    }

    for(int i = 1; i<=n; i++){
        auto [t, p] = tp[i];
        if(i+t-1 > n) continue;
        for(int j = 0; j<i; j++){
            dp[i+t-1] = max(dp[i+t-1], dp[j]+p);
        }
    }

    int ans = 0;
    for(int i = 0; i<=n+1; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}