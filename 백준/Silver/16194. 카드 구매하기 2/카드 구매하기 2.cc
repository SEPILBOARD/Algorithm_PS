#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int dp[1001];

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> dp[i];
    
    for(int i = 1; i<n; i++){
        for(int j = 1; i+j<=n; j++){
            dp[i+j] = min(dp[i+j], dp[i]+dp[j]);
        }
    }
    cout << dp[n];
    return 0;
}