#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;
int p[200'001];
ll k;

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++) cin >> p[i];
    cin >> k;

    ll ans = 0;
    for(int i = 0; i<n; i++){
        ll curp = p[i];
        while(curp <= k){
            ans += k/curp;
            curp *= p[i];
        }
    }
    cout << ans;
    return 0;
}