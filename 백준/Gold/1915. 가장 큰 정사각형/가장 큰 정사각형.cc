#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, m;
char a[1001][1001];

int dp[1001][1001];

signed main()
{
    FASTIO;
    int ans = 0;

    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> a[i][j];
            if(a[i][j] == '1'){
                dp[i][j] = 1;
                ans = 1;
            }
        }
    }

    for(int i = 1; i<n; i++){
        for(int j = 1; j<m; j++){
            if(a[i][j] != '1') continue;
            
            dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
            ans = max(ans, dp[i][j]*dp[i][j]);
        }
    }

    cout << ans <<"\n";
    return 0;
}