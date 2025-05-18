#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int a[3001];
int dp[3001];
int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++) cin >> a[i];
    memset(dp, 0x7f, sizeof(dp));
    
    dp[0] = 0;
    for(int i = 0; i<n; i++){
        for(int j = 1; j<=a[i] && i+j<=n; j++){
            dp[i+j] = min(dp[i+j], dp[i]+1);
        }
    }
    cout << dp[n];
    return 0;
}