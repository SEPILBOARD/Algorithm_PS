#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define MOD 10'007

int n;
int dp[1010];

int main()
{
    FASTIO;
    cin >> n;
    dp[0] = 1;
    for(int i = 0; i<n; i++){
        dp[i+1] = (dp[i+1]+dp[i])%MOD;
        dp[i+2] = (dp[i+2]+ 2*dp[i]%MOD)%MOD;
    }
    cout << dp[n];
    return 0;
}