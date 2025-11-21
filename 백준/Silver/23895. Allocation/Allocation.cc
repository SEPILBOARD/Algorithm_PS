#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int n, b;
int a[101];

void solve()
{
    cin >> n >> b;
    for(int i = 0; i<n; i++) cin >> a[i];
    sort(a, a+n);

    int ans = 0;
    for(int i = 0; i<n; i++){
        if(a[i]<=b){
            b -= a[i];
            ans++;
        }
        else break;
    }
    cout << ans << "\n";    
}

signed main()
{
    FASTIO;
    int tc; cin >> tc;
    for(int i = 1; i<=tc; i++){
        cout << "Case #" << i <<": ";
        solve();
    }
    return 0;
}