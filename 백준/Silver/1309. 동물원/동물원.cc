#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define MOD 9901

int n;
int dp[100'001][3];

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<3; i++) dp[1][i] = 1;

    for(int i = 1; i<n; i++){
        dp[i+1][0] = ((dp[i][0]+dp[i][1])%MOD+dp[i][2])%MOD;
        dp[i+1][1] = (dp[i][0] + dp[i][2])%MOD;
        dp[i+1][2] = (dp[i][0] + dp[i][1])%MOD;
    }
    cout << ((dp[n][0] + dp[n][1])%MOD + dp[n][2])%MOD;
    return 0;
}