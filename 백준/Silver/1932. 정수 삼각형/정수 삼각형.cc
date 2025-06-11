#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int tgl[501][501];

int dp[501][501];

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            cin >> tgl[i][j];
        }
    }
    
    for(int i = 1; i<=n; i++) dp[n][i] = tgl[n][i];

    for(int i = n-1; i>=1; i--){
        for(int j = 1; j<=i; j++){
            dp[i][j] = tgl[i][j] + dp[i+1][j];
            dp[i][j] = max(dp[i][j], tgl[i][j] + dp[i+1][j+1]);
        }
    }
    cout << dp[1][1];
    return 0;
}