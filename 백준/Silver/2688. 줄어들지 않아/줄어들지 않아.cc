#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

int n;
int dp[65][10];

signed main()
{
    FASTIO;

    dp[1][0] = 1;
    for(int i = 1; i<10; i++){
        dp[1][i] = dp[1][i-1]+1;
    }

    for(int i = 2; i<=64; i++){
        dp[i][0] = dp[i-1][9];
        for(int j = 1; j<10; j++){
            dp[i][j] = dp[i][j-1];
            dp[i][j] += dp[i-1][9] - dp[i-1][j-1];
        }
    }

    int t; cin >> t;
    while(t--){
        cin >> n;
        cout << dp[n][9] <<"\n";
    }
    return 0;
}