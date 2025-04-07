#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;
char c[20][20];
int dp[101][1<<11];

void solve()
{
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> c[i][j];
        }
    }
    if(m==1){
        int cnt = 0;
        for(int i = 0; i<n; i++) if(c[i][0] == '.') cnt++;
        cout << cnt <<"\n";
        return;
    }
    memset(dp, 0, sizeof(dp));
    // dp[0][0] = 0;
    if(c[0][0] != 'x') dp[0][(1<<m) |1] = 1;

    for(int i = 0; i<n*m-1; i++){
        for(int j = 0; j<(1<<(m+1)); j++){
            //i+1에 배치X
            // dp[i+1][j>>1] = dp[i][j];
            dp[i+1][j>>1] = max(dp[i+1][j>>1], dp[i][j]);

            //i+1에 배치
            if(j&1) continue;
            int y = (i+1)%m;
            if(c[(i+1)/m][y] != 'x'){
                if(y == m-1){
                    // dp[i+1][(j>>1)|(1<<(m-2))] = dp[i][j]+1;
                    dp[i+1][(j>>1)|(1<<(m-2))] = max(dp[i+1][(j>>1)|(1<<(m-2))], dp[i][j]+1);
                }

                else if(y == 0){
                    // dp[i+1][(j>>1) |(1<<m) |1] = dp[i][j]+1;
                    dp[i+1][(j>>1) |(1<<m) |1] = max(dp[i+1][(j>>1) |(1<<m) |1], dp[i][j]+1);
                }

                else{
                    // dp[i+1][(j>>1) |1 |(1<<(m-2)) |(1<<m)] = dp[i][j]+1;
                    dp[i+1][(j>>1) |1 |(1<<(m-2)) |(1<<m)] = max(dp[i+1][(j>>1) |1 |(1<<(m-2)) |(1<<m)], dp[i][j]+1);
                }
            }
        }
    }

    // for(int j = 0; j<m*n; j++){
    //     cout << j <<"\n";
    //     for(int i = 0; i<1<<(m+1); i++){
    //         bitset<32> b(i);
    //         cout << b<< " "<<dp[j][i] <<":\n";
    //     }
    // }

    int ans = 0;
    for(int i = 0; i<(1<<m); i++) ans = max(ans, dp[n*m-1][i]);
    cout << ans <<"\n";
}

int main(){
    FASTIO
    int t; cin >> t;
    while(t--) solve();
    return 0;
}