#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int k, n;
int dp[15][15];

signed main()
{
    FASTIO;
    dp[0][0] = 0;
    for(int i = 1; i<=14; i++) dp[0][i] = i;

    for(int i = 0; i<14; i++){
        for(int j = 1; j<=14; j++){
            dp[i+1][j] = dp[i+1][j-1] + dp[i][j];
        }
    }

    int tc; cin >> tc;
    while(tc--){
        cin >> k >> n;
        cout << dp[k][n] <<"\n";
    }

    return 0;
}