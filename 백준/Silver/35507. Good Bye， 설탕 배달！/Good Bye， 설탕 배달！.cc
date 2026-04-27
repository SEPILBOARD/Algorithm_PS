#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;


void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> b(n+1);
    vector<ll> c(n+1);
    vector<ll> p(n+1);

    for(int i = 0; i<n; i++){
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
        cin >> p[i];
    }

    ll curA = 0;
    ll curB = 0;
    ll curC = 0;
    ll curP = 0;

    ll r = 0;

    for(int i = 0; i<n; i++){
        ll na = max(0ll, a[i]-curA);
        ll nb = max(0ll, b[i]-curB);
        ll nc = max(0ll, c[i]-curC);
        ll np = p[i]-curP;

        ll nall = na+nb+nc;
    
        if(nall-r>np-1){
            cout << "NO\n";
            // cout << i;
            return;
        }

        if(nall>np-1){
            r-= nall-np-1;
        }
        else if(nall<np-1){
            r+= np-1-nall;
        }
        curA = max(curA, a[i]);
        curB = max(curB, b[i]);
        curC = max(curC, c[i]);
        curP = p[i];
    }
    cout << "YES\n";

}

signed main()
{
    FASTIO;
    int tc; cin >> tc;
    while(tc--) solve();    
    return 0;
}