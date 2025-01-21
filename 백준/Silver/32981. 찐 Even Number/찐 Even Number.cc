#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

#define MOD 1000000007;

int q;

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

int main()
{
    FASTIO;
    cin >> q;
    while(q--){
        int n; cin >> n;
        int ans = 4 * power(5, n-1) % MOD;
        if(ans == 4) ans++;
        cout << ans <<"\n";
    }
    return 0;
}