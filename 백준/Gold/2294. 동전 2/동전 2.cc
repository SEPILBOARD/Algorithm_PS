#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, k;
bool v[100'001];
vector<int> c;

int dp[101][10'001];

int main()
{
    FASTIO;
    cin >> n >> k;
    for(int i = 0; i<n; i++){
        int e; cin >> e;
        if(v[e]) continue;
        v[e] = true;
        c.push_back(e);
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    n = c.size();
    for(int i = 0; i<n; i++){
        for(int j = 0; j<=k; j++){
            if(dp[i][j] == -1) continue;
            for(int cnt = 0; cnt*c[i]+j<=k; cnt++){
                if(dp[i+1][cnt*c[i]+j] == -1) dp[i+1][cnt*c[i]+j] = dp[i][j] + cnt;
                else dp[i+1][cnt*c[i]+j] = min(dp[i+1][cnt*c[i]+j], dp[i][j] + cnt);
            }
        }
    }

    cout << dp[n][k];
    return 0;
}