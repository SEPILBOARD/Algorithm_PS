#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;
#define MOD 1'000'000'003

int n, k;
int dp1[1010][1010][2];
int dp0[1010][1010][2];

signed main()
{
    FASTIO;
    cin >> n >> k;

    dp1[0][1][1] = 1;
    for(int i = 0; i<n; i++){
        for(int cnt = 0; cnt<=i+1; cnt++){
            dp1[i+1][cnt][0] = (dp1[i][cnt][0]+dp1[i][cnt][1])%MOD;
            dp1[i+1][cnt+1][1] = dp1[i][cnt][0];
        }
    }

    dp0[0][0][0] = 1;
    for(int i = 0; i<n; i++){
        for(int cnt = 0; cnt<=i+1; cnt++){
            dp0[i+1][cnt][0] = (dp0[i][cnt][0]+dp0[i][cnt][1])%MOD;
            dp0[i+1][cnt+1][1] = dp0[i][cnt][0];
        }
    }
    cout << (1LL*dp1[n-1][k][0] + dp0[n-1][k][1] + dp0[n-1][k][0])%MOD;
    return 0;
}