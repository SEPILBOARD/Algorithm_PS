#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int r, c, w;
long long int dp[32][32];

int main()
{
    FASTIO;
    cin >> r >> c >> w;

    dp[1][1] = 1;
    for(int i = 2; i<= 30; i++){
        for(int j = 1; j<=i; j++){
            if(j==1 || j==i) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
        }
    }

    long long int ans = 0;
    for(int i = r; i<r+w; i++){
        for(int j = c; j<=(c+(i-r)); j++){
            ans += dp[i][j];
        }
    }
    cout << ans;
    return 0;
}