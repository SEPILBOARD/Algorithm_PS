#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int n;
ll dp[100'001][3];
ll a[100'001][3];

void solve()
{
    for(int i = 0; i<n; i++){
        for(int j = 0; j<3; j++){
            cin >> a[i][j];
        }
    }

    a[0][0] = 1e+9+2;
    memset(dp, 0x7f, sizeof dp);
    dp[0][1] = a[0][1];

    for(int i = 0; i<n; i++){
        for(int j = 0; j<3; j++){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]+a[i+1][j]);
            if(j != 0) dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j]+a[i+1][j-1]);
            if(j != 2){
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+a[i+1][j+1]);
                dp[i][j+1] = min(dp[i][j+1], dp[i][j]+a[i][j+1]);
            }   
        }
    }
    cout << dp[n-1][1] <<"\n";
}

signed main()
{
    FASTIO;
    cin >> n;
    int num = 1;
    while(n){
        cout << num++ <<". ";
        solve();
        cin >> n;
    }
    return 0;
}