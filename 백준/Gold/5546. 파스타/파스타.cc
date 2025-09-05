#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define MOD 10000

int n, m;
int pst[111];
int dp[111][4][4];

signed main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        pst[a] = b;
    }

    for(int i = 1; i<=3; i++){
        if(pst[2] != 0 && pst[2] != i) continue;
        for(int j = 1; j<=3; j++){
            if(pst[1] != 0 && pst[1] != j) continue;
            dp[2][i][j] = 1;
        }
    }

    for(int d = 2; d<=n; d++){
        for(int i = 1; i<=3; i++){
            for(int j = 1; j<=3; j++){
                if(pst[d+1] == i && pst[d+1] == j) continue;

                if(pst[d+1] == 0){
                    for(int cur = 1; cur<=3; cur++){
                        if(cur == i && cur ==j) continue;

                        dp[d+1][cur][i] = (dp[d+1][cur][i] + dp[d][i][j])%MOD;
                    }
                }
                else{
                    dp[d+1][pst[d+1]][i] = (dp[d+1][pst[d+1]][i]+ dp[d][i][j])%MOD;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i<=3; i++){
        for(int j = 1; j<=3; j++){
            // cout << i << "," <<j <<": " << dp[2][i][j]<<"\n";
            ans = (ans+dp[n][i][j])%MOD;
        }
    }
    cout << ans;
    return 0;
}