#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, M;
int m[101];
int c[101];
int dp[101][10001];

signed main()
{
    FASTIO;
    memset(dp, -1, sizeof(dp));
    cin >> n >> M;
    int csum = 0;
    for(int i = 0; i<n; i++) cin >> m[i];
    for(int i = 0; i<n; i++){
        cin >> c[i];
        csum += c[i];
    }
    dp[0][0] = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<=csum; j++){
            if(dp[i][j] == -1) continue;
            
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            dp[i+1][j+c[i]] = max(dp[i+1][j+c[i]], dp[i][j]+m[i]);
        }
    }
    
    for(int i = 0; i<=csum; i++){
        if(dp[n][i]>=M){
            cout << i;
            break;
        }
    }
    return 0;
}