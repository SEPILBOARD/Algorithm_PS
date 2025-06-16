#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, k;
int c[101];
int dp[10'001];

int main()
{
    FASTIO;
    cin >> n >> k;
    for(int i = 0; i<n; i++) cin >> c[i];
    dp[0] = 1;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j+c[i]<=k; j++){
            dp[j+c[i]] += dp[j];
        }
    }
    
    cout << dp[k];
    return 0;
}