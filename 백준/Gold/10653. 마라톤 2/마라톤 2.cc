#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, k;
pair<int, int> cp[500];

int dp[500][501];

int main()  
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k; if(k==n-1) k--;
    for(int i =0; i<n; i++)
    {
        int a,b; cin >> a >> b;
        cp[i] = make_pair(a, b);
    }
    memset(dp, -1, sizeof(dp));

    dp[0][0] = 0;

    for(int i =1; i<n; i++)
    {
        for(int j = 0; j<i; j++)
        {
            if(j>k) break;
            for(int aj = 0; aj<=j; aj++)
            {
                if(dp[i-aj-1][j-aj] == -1) continue;
                if(dp[i][j] == -1) dp[i][j] = 2e+9+10597;
                int dis = abs(cp[i].first-cp[i-aj-1].first) + abs(cp[i].second-cp[i-aj-1].second) + dp[i-aj-1][j-aj];
                dp[i][j] = min(dp[i][j], dis);
            }
        }
    }
    int ans = 2e+9+10597;
    for(int i =0; i<=k; i++)
        ans = min(ans,dp[n-1][i]);
    cout << ans;
    return 0;
}