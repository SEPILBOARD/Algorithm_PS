#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, ans;
int dp[250][250];

int main()
{
    FASTIO;
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> dp[i][i];
        ans = max(ans, dp[i][i]);
    }

    for(int ln = 1; ln<=n; ln++){
        for(int i = 0; i+ln-1<n; i++){
            for(int j = i; j<i+ln-1; j++){
                if(dp[i][j] == -1 || dp[j+1][i+ln-1] == -1) continue;
                if(dp[i][j] == dp[j+1][i+ln-1]){
                    dp[i][i+ln-1] = dp[i][j]+1;
                    ans = max(ans, dp[i][i+ln-1]);
                }
            }
        }
    }
    cout << ans;
    return 0;
}