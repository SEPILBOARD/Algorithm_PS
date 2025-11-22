#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int n;
ll dp[40];

signed main()
{
    FASTIO;
    cin >> n;
    
    dp[0] = 1;

    for(int i = 1; i<=n; i++){
        for(int j = 0; j<i; j++){
            dp[i] += dp[j]*dp[i-1-j];
        }
    }
    cout << dp[n];
    
    return 0;
}