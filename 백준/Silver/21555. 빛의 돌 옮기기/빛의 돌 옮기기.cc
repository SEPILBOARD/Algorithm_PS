#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

int n, k;
int a[200000][2];
int dp[200000][2];

signed main()
{
    FASTIO;
    cin >> n >> k;
    for(int i = 0; i<n; i++) cin >> a[i][0];
    for(int i = 0; i<n; i++) cin >> a[i][1];
    
    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    for(int i = 1; i<n; i++){
        dp[i][0] = dp[i-1][0] + a[i][0];
        dp[i][0] = min(dp[i][0], dp[i-1][1] + a[i][0]+k);
        dp[i][1] = dp[i-1][1] + a[i][1];
        dp[i][1] = min(dp[i][1], dp[i-1][0] + a[i][1]+k);
    }
    cout << min(dp[n-1][0], dp[n-1][1]);
    return 0;
}