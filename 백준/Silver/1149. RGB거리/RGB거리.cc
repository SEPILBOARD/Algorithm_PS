#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int cost[1002][3];

int dp[1002][3];

int main()
{
    FASTIO;
    
    memset(dp, 0x7f, sizeof(dp));
    cin >> n;
    for(int i = 0; i<n; i++) cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    for(int i = 0; i<3; i++) dp[0][i] = cost[0][i];

    for(int i = 0; i<n; i++){
        dp[i+1][0] = cost[i+1][0] + dp[i][1];
        dp[i+1][0] = min(dp[i+1][0], cost[i+1][0] + dp[i][2]);

        dp[i+1][1] = cost[i+1][1] + dp[i][0];
        dp[i+1][1] = min(dp[i+1][1], cost[i+1][1] + dp[i][2]);

        dp[i+1][2] = cost[i+1][2] + dp[i][0];
        dp[i+1][2] = min(dp[i+1][2], cost[i+1][2] + dp[i][1]);
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
    return 0;
}