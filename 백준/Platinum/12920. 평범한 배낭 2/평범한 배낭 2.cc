#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

int n, m;
int dp[1401][10'001];

signed main()
{
    FASTIO;
    cin >> n >> m;
    vector<pair<int, int>> a;
    for(int i = 0; i<n; i++){
        int v, c, k;
        cin >> v >> c >> k;
        
        for(int j = 1; k>0; j *=2){
            int cnt = min(j, k);
            a.push_back({v*cnt, c*cnt});
            k -= cnt;
        }
    }
    
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 0; i<a.size(); i++){
        for(int j = 0; j<=m; j++){
            if(dp[i][j] == -1) continue;

            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(j+a[i].first <= m){
                dp[i+1][j+a[i].first] = max(dp[i+1][j+a[i].first], dp[i][j]+a[i].second);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i<=m; i++){
        ans = max(ans, dp[a.size()][i]);
    }
    cout << ans << "\n";
    return 0;
}