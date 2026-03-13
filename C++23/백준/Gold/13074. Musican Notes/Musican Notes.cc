#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

ll comb[100][100];

void solve()
{
    int n;
    cin >> n;

    int lcnt = n>>1;
    int scnt = 0;
    if(lcnt&1){
        lcnt--;
        scnt = 2;
    }

    ll ans = 0LL;
    while(lcnt>=scnt){
        int x = lcnt+scnt>>1;
        ans += comb[x][lcnt/2]*comb[x][lcnt/2];

        lcnt -= 2;
        scnt += 4;
    }
    cout << ans <<"\n";
}

signed main()
{
    comb[0][0] = 1;
    for(int i = 1; i<65; i++){
        for(int j = 0; j<=i; j++){
            if(j == 0 || j == i) comb[i][j] = 1;
            else{
                comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
            }
        }
    }

    FASTIO;
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}