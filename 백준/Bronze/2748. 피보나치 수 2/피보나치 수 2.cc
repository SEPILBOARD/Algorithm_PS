#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int n;
ll dp[100];

ll fibo(int x)
{
    if(x == 1 || x == 2){
        dp[x] = 1LL;
        return 1LL;
    }

    if(dp[x] != -1) return dp[x];
    ll &ret = dp[x];
    ret = fibo(x-1) + fibo(x-2);

    return ret;
}

signed main()
{
    FASTIO;
    cin >> n;
    memset(dp, -1, sizeof(ll)*(n+1));
    cout << fibo(n);
    return 0;
}