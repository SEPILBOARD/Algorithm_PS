#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m, k;
int w[1001];
int l[1001];

int dp[1001][1001];

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0 ; i<n; i++) cin >> w[i];
    cin >> m;
    for(int i = 0 ; i<m; i++) cin >> l[i];
    cin >> k;

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            dp[i][j] = -1e9;

    dp[0][0] = 0;
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=m; j++){
            if(dp[i][j] == -1e9) continue;

            if(i<n)
                dp[i+1][j] = max(dp[i+1][j], dp[i][j] + w[i]);

            if(j<m){
                int b = ((dp[i][j] % k) + k) % k;
                int loss = (b == 0 ? l[j] : min(l[j], b));
                dp[i][j+1] = max(dp[i][j+1], dp[i][j] - loss);
            }
        }
    }

    cout << dp[n][m] << '\n';

    return 0;
}