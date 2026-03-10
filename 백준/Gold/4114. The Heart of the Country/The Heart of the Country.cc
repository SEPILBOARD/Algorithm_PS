#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int n, k;

void solve()
{
    vector<int> a(n);
    vector<int> dp(n);
    vector<vector<int>> adj(n);

    for(int i = 0; i<n; i++){
        int m;
        cin >> a[i] >> m;
        for(int j = 0; j<m; j++){
            int nxt;
            cin >> nxt;
            adj[i].push_back(nxt);
        }
    }

    vector<char> v(n, false);
    queue<int> q;
    for(int i = 0; i<n; i++){
        dp[i] = a[i];

        for(int nxt: adj[i]){
            dp[i] += a[nxt];
        }

        if(dp[i]<k){
            v[i] = true;
            q.push(i);
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int nxt: adj[cur]){
            if(v[nxt]) continue;
            
            dp[nxt] -= a[cur];
            if(dp[nxt]<k){
                v[nxt] = true;
                q.push(nxt);
            }
        }
    }
    
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(v[i]) continue;
        cnt++;
        ans += a[i];
    }
    cout << cnt << " " << ans <<'\n';
}

signed main()
{
    FASTIO;
    cin >> n >> k;
    while(n !=0 && k!=0){
        solve();
        cin >> n >> k;
    }
    return 0;
}