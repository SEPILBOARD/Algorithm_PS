#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;
#define MOD 1'000'000'007

int n;
ll dp[1010][7];

signed main()
{
    FASTIO;
    cin >> n;
    dp[0][0] = 1;

    for(int i = 0; i<n; i++){
        dp[i+1][1] = (dp[i+1][1]+dp[i][0])%MOD;
        dp[i+1][4] = (dp[i+1][4]+dp[i][0])%MOD;

        dp[i+1][0] = (dp[i+1][0]+dp[i][1])%MOD;
        dp[i+1][6] = (dp[i+1][6]+dp[i][1])%MOD;
        dp[i+1][1] = (dp[i+1][1]+dp[i][6])%MOD;

        dp[i+1][0] = (dp[i+1][0]+dp[i][4])%MOD;
        dp[i+1][3] = (dp[i+1][3]+dp[i][4])%MOD;
        dp[i+1][4] = (dp[i+1][4]+dp[i][3])%MOD;
        
        dp[i+2][0] = (dp[i+2][0]+dp[i][0])%MOD;
    }
    cout << dp[n][0];
    return 0;
}