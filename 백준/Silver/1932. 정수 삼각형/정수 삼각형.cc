#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int dp[501][501];

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=i; j++)
            cin >> dp[i][j];

    for(int i = n-1; i>=1; i--)
        for(int j = 1; j<=i; j++)
            dp[i][j] += max(dp[i+1][j], dp[i+1][j+1]);
            
    cout << dp[1][1];
    return 0;
}