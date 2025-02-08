#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;
int t[501][500];
int dp[501][500];

int main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<m; j++){
            cin >> t[i][j];
        }
    }
    memset(dp, 0x7f, sizeof(dp));
    for(int i = 0; i<m; i++) dp[0][i] = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<m; j++){
            for(int k = 0; k<m; k++){
                if(j == k) continue;
                dp[i][j] = min(dp[i][j], dp[i-1][k] + t[i][j]);
            }
        }
    }
    int ans = 987654321;
    for(int i = 0; i<m; i++) ans = min(ans, dp[n][i]);
    cout << ans;
    return 0;
}