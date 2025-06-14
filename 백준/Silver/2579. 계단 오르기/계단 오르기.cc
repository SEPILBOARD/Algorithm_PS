#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int a[330];
int dp[330][2];

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> a[i];
    
    dp[1][0] = a[1];
    for(int i = 0; i<n; i++){
        dp[i+1][1] = max(dp[i+1][1], dp[i][0] + a[i+1]);
        dp[i+2][0] = max(dp[i+2][0], dp[i][0] + a[i+2]);
        dp[i+2][0] = max(dp[i+2][0], dp[i][1] + a[i+2]);
    }

    cout << max(dp[n][0], dp[n][1]);
    return 0;
}