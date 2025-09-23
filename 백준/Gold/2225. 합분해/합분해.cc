#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;
#define MOD 1'000'000'000

int n, k;
int dp[201][201];

int go(int x, int cnt)
{
    if(dp[x][cnt] != -1) return dp[x][cnt];
    
    int ret = 0;
    for(int j = 0; j<=x; j++){
        ret = (ret+go(x-j, cnt-1))%MOD;
    }
    return dp[x][cnt] = ret;
}

signed main()
{
    FASTIO;
    cin >> n >> k;

    memset(dp, -1, sizeof(dp));
    for(int i = 0; i<=n; i++){
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    cout << go(n, k);
    return 0;
}