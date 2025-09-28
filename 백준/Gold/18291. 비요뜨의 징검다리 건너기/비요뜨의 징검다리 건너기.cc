#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;
#define MOD 1'000'000'007

ll pw(int x, int y)
{
    if(y == 0) return 1;
    ll ret = pw(x, y/2);
    ret = ret*ret %MOD;
    if(y&1) ret = ret*x%MOD;
    return ret;
}

int n;

void solve()
{
    cin >> n;
    if(n == 1) cout << 1 <<"\n";
    else cout << pw(2, n-2) <<"\n";
}

signed main()
{
    FASTIO;
    int tc; cin >> tc;
    while(tc--) solve();    
    return 0;
}