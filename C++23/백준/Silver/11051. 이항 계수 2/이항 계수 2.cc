#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

#define MOD 10'007
int n, k;

ll comb[1'001][1'001];

signed main()
{
    FASTIO;

    for(int i = 0; i<=1'000; i++){
        for(int j = 0; j<=i; j++){
            if(j==0 || j==i) comb[i][j] = 1LL;
            else comb[i][j] = (comb[i-1][j-1]+comb[i-1][j])%MOD;
        }
    }

    cin >> n >> k;
    cout << comb[n][k] <<"\n";
    
    return 0;
}