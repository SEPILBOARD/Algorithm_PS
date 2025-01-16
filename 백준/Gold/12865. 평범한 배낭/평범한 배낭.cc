#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, k;
int dp[101][100001];
pair<int, int> obj[101];

int main()
{
    FASTIO;
    cin >> n >> k;
    for(int i = 1; i<=n; i++){
        int w, v; cin >> w >> v;
        obj[i] = {w,v};
    }
    
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=k; j++){
            if(dp[i-1][j] == -1) continue;
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if(j+obj[i].first <= k)
                dp[i][j+obj[i].first] = max(dp[i][j+obj[i].first], dp[i-1][j]+obj[i].second);
        }
    }

    int ans = -1;
    for(int i = 0; i <=k; i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans;
    return 0;
}