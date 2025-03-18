#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int
#define MOD 1000000007

int m, ans;

int power(int a, int ex)
{
    if(ex == 0) return 1;
    int temp = power(a, ex/2)%MOD;
    if(ex % 2 ==1){
        int k = temp * temp % MOD;
        k = k * a%MOD;
        return k;
    }
    return temp * temp % MOD;
}

signed main()
{
    FASTIO;
    cin >> m;
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> b >> a;
        ans += ((a%MOD) * (power(b,MOD-2)%MOD))%MOD;
        ans %= MOD;
    }
    cout << ans;
    return 0;
}