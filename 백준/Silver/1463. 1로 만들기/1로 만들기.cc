#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int dp[3'000'001];

int main()
{
    FASTIO;
    int n;
    cin >> n;
    
    memset(dp, 0x7f, sizeof(dp));
    dp[1] = 0;


    for(int i = 1; i<n; i++){
        dp[2*i] = min(dp[2*i], dp[i]+1);
        dp[3*i] = min(dp[3*i], dp[i]+1);
        dp[i+1] = min(dp[i+1], dp[i]+1);
    }
    cout << dp[n];
    return 0;
}