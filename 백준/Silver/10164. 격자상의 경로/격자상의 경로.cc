#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int n, m, k;
ll dp1[20][20];
ll dp2[20][20];

signed main()
{
    FASTIO;
    cin >> n >> m >> k;
    
    int ki = (k-1)/m + 1;
    int kj = (k-1)%m + 1;
    if(k == 0){
        ki = 1;
        kj = 1;
    }

    dp1[1][1] = 1ll;
    for(int i = 1; i<=ki; i++){
        for(int j = 1; j<=kj; j++){
            dp1[i+1][j] = dp1[i][j] + dp1[i+1][j-1];
            dp1[i][j+1] = dp1[i][j] + dp1[i-1][j+1];
        }
    }

    dp2[ki][kj] = dp1[ki][kj];
    for(int i = ki; i<=n; i++){
        for(int j = kj; j<=m; j++){
            dp2[i+1][j] = dp2[i][j] + dp2[i+1][j-1];
            dp2[i][j+1] = dp2[i][j] + dp2[i-1][j+1];
        }
    }

    cout << dp2[n][m];
    return 0;
}