#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int a[100'001][2];
int dp[100'001][3];

void solve()
{
    cin >> n;
    for(int k = 0; k<2; k++){
        for(int i = 1; i<=n; i++){
            cin >> a[i][k];
        }
    }
    
    for(int i = 0; i<n; i++){
        dp[i+1][0] = 0;
        for(int k = 0; k<3; k++){
            dp[i+1][0] = max(dp[i+1][0], dp[i][k]);
        }
        dp[i+1][1] = max(dp[i][0]+a[i+1][0], dp[i][2]+a[i+1][0]);
        dp[i+1][2] = max(dp[i][0]+a[i+1][1], dp[i][1]+a[i+1][1]);
    }
    cout << max(dp[n][1], dp[n][2]) <<"\n";
}

int main()
{
    FASTIO;
    int tc; cin >>tc;
    while(tc--) solve();
    return 0;
}