#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

#define MOD 1'000'000'007
#define MAX 4'000'000

ll pw(ll a, ll b)
{
    if(b == 0) return 1LL;
    
    ll ret = pw(a, b/2);
    ret = ret*ret%MOD;
    if(b&1) return ret*a%MOD;
    else return ret;
}

int m;

ll facto[4'000'001];
ll invf[4'000'001];

ll comb(int a, int b)
{
    if(a<b) return 0LL;
    ll ret = facto[a]*invf[b]%MOD;
    ret = ret*invf[a-b]%MOD;
    return ret;
}


signed main()
{
    FASTIO;

    facto[0] = 1LL;
    for(int i = 1; i<=MAX; i++){
        facto[i] = facto[i-1]*i%MOD;
    }
    invf[MAX] = pw(facto[MAX], MOD-2);
    for(int i = MAX-1; i>=0; i--){
        invf[i] = invf[i+1]*(i+1)%MOD;
    }

    cin >> m;
    for(int q = 0; q<m; q++){
        int n, k;
        cin >> n >> k;
        cout << comb(n, k) <<"\n";
    }

    return 0;
}