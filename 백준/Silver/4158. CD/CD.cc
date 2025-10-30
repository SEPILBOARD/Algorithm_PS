#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, m;

void solve()
{
    int ans = 0;
    
    vector<int> v;
    v.assign(n, 0);
    for(int i = 0; i<n; i++){
        cin >> v[i];
    }
    
    for(int i = 0; i<m; i++){
        int e;
        cin >> e;
        auto it = lower_bound(v.begin(), v.end(), e);
        if(it != v.end() && *it == e) ans++;
    }
    
    cout << ans << "\n";
}

signed main()
{
    FASTIO;
    cin >> n >> m;
    while(n!=0){
        solve();
        cin >> n >> m;
    }
    
    return 0;
}