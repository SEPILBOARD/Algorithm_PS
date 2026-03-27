#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define ll long long int
#define MOD 1'000'000'007

int n, m;
int dp[301][1<<18];

long long int power(int a, int ex)
{
    if(ex == 0) return 1;
    long long int temp = power(a, ex/2)%MOD;
    if(ex % 2 ==1){
        long long int k = temp * temp % MOD;
        k = k * a%MOD;
        return k;
    }
    return temp * temp % MOD;
}

signed main()
{
    FASTIO;
    cin >> n >> m;
    int col = min(n, m);
    int row = max(n, m);

    if(col == 1){
        cout << power(2,row)%MOD;
        return 0;
    }

    dp[0][0] = 1;
    for(int i = 0; i<=col*row-1; i++){
        if(i%col == 0){
            for(int j = 0; j<(1<<(col+1)); j++){
                dp[i+1][j>>1] = (dp[i+1][j>>1] + (ll)dp[i][j])%MOD;
                dp[i+1][(j>>1)|(1<<col)] = (dp[i+1][(j>>1)|(1<<col)] + (ll)dp[i][j])%MOD;
            }
        }
        
        else{
            for(int j = 0; j<(1<<(col+1)); j++){
                dp[i+1][j>>1] = (dp[i+1][j>>1] + (ll)dp[i][j])%MOD;
                if(j&1 && j&2 && j&(1<<col)) continue;
                dp[i+1][(j>>1)|(1<<col)] = (dp[i+1][(j>>1)|(1<<col)] + (ll)dp[i][j])%MOD;
            }
        }
    }
    int last = col*row;
    ll ans = 0;
    for(int i=0; i<(1<<(col+1)); i++){
        ans = (ans + dp[last][i])%MOD;
    }
    cout <<ans;
    return 0;
}