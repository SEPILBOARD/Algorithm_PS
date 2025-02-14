#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m, k;
int candy[30001];
int p[30001];
int cnt[30001];
int dp[30002][3001];    

int Find(int x)
{
    if(x == p[x]) return x;
    else return p[x] = Find(p[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x != y){
        p[y] = x;
        candy[x] += candy[y];
        candy[y] = 0;
        cnt[x] += cnt[y];
        cnt[y] = 0;
    }
}

signed main()
{
    FASTIO;
    cin >> n >> m >> k;
    for(int i = 1; i<=n; i++) cin >> candy[i];

    memset(dp, -1, sizeof(dp));
    for(int i = 0; i<=n; i++){
        p[i] = i;
        cnt[i] = 1;
        dp[i][0] = 0;
    }

    while(m--){
        int a, b; cin >> a >> b;
        Union(a, b);
    }

    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=3000; j++){
            if(dp[i-1][j] == -1) continue;
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            
            if(j+cnt[i] <k) dp[i][j+cnt[i]] = max(dp[i][j+cnt[i]], dp[i-1][j]+candy[i]);
        }
    }
    int ans = 0;
    for(int i = 0; i<=3000; i++) ans = max(ans, dp[n][i]);
    cout << ans;
    return 0;
}