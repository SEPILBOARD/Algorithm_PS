#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;
#define MOD 1'000'000'009

int t, n, m;
int dp[1010][1010];

int go(int x, int cnt)
{
    if(dp[x][cnt] != -1) return dp[x][cnt];

    // cout << x << ", " << cnt <<"\n";
    int ret = 0;
    if(cnt>1){
        if(x>1) ret = (ret + go(x-1, cnt-1))%MOD;
        if(x>2) ret = (ret + go(x-2, cnt-1))%MOD;
        if(x>3) ret = (ret + go(x-3, cnt-1))%MOD;
    }
    return dp[x][cnt] = ret;
}

signed main()
{
    FASTIO;
    memset(dp, -1, sizeof(dp));

    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[3][1] = 1;

    cin >> t;
    for(int i = 0; i<t; i++){
        cin >> n >> m;
        cout << go(n, m) <<"\n";
    }
    
    return 0;
}