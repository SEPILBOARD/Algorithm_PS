#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;
long long int dp[32][32];

int main()
{
    FASTIO;
    dp[0][0] = 1;
    for(int i = 1; i<= 30; i++){
        for(int j = 0; j<=i; j++){
            if(j==0 || j==i) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
        }
    }

    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        cout << dp[m][n] <<"\n";
    }

    return 0;
}