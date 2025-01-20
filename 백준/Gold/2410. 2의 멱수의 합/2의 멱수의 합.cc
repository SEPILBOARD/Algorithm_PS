#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define DIV 1000000000

int n;
int dp[1000001];

int main()
{
    FASTIO;
    cin >> n;
    dp[1] = 1;
    for(int i = 2; i<=n; i++){
        if(i%2 == 1) dp[i] = dp[i-1];
        else dp[i] = (dp[i-1] + dp[i/2])%DIV;
    }
    cout << dp[n];
    return 0;
}