#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, k;
vector<pair<int, int>> adj[5'002];
bool v[5'002];
int dist[5'002];

pair<int, int> dp[5'002];

signed main()
{
    FASTIO;
    cin >> n >> k;
    for(int i = 1; i<n; i++){
        int u, v, x;
        cin >> u >> v >> x;
        adj[u].push_back({v, x});
        adj[v].push_back({u, x});

        dp[i] = {-1, -1};
    }

    if(n == 1){
        if(k == 0) cout << "0";
        else cout << "1\n0";
        return 0;
    }

    queue<pair<int,int>> q;
    v[1] = true;
    q.push({1, 0});
    while(!q.empty()){
        auto[cur, d] = q.front();
        q.pop();

        dist[cur] = d;
        for(auto[next, x]: adj[cur]){
            if(v[next]) continue;
            v[next] = true;
            q.push({next, d+x});
        }
    }
    
    sort(dist+1, dist+1+n);
    // for(int i = 1; i<=n; i++) cout << dist[i] <<" ";
    // cout << "\n";

    stack<int> ans;

    dp[1] = {0, 0};
    dp[n] = {1e+9, 0};
    set<int> psb;
    psb.insert(1);
    bool flag = false;
    for(int i = 1; i<=n; i++){
        if(dist[i+1] == dist[i]) continue;
        if(i == k){
            flag = true;
            ans.push(dist[i]);
            break;
        }

        for(int e: psb){
            if(i-e == k){
                flag = true;
                dp[i-e] = {dist[i], e};
                int cur = i-e;
                while(dp[cur].second != 0){
                    ans.push(dp[cur].first);
                    cur = dp[cur].second;
                }
                ans.push(dp[cur].first);
                break;
            }
            
            if(psb.count(i-e) == 0){
                psb.insert(i-e);
                dp[i-e] = {dist[i], e};
            }
        }
        if(flag) break;

        if(dp[i].first == -1){
            dp[i] = {dist[i], 0};
            psb.insert(i);
        }
    }
    
    if(flag){
        cout << ans.size() <<"\n";
        while(!ans.empty()){
            cout << ans.top() <<" ";
            ans.pop();
        }
    }
    else{
        cout << "-1";
    }
    
    return 0;
}