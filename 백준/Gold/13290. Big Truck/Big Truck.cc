#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int n, m;
int a[101];
vector<pair<int, int>> adj[101];
int dist[101];
bool v[101];

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> a[i];
    
    cin >> m;
    for(int i = 0; i<m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    memset(dist, 0x7f, sizeof(int)*(n+1));
    dist[1] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        auto[d, cur] = pq.top();
        pq.pop();

        if(dist[cur] != d) continue;
        for(auto[next, nw]: adj[cur]){
            if(dist[next] <= d+nw) continue;
            dist[next] = d+nw;
            pq.push({dist[next], next});
        }
    }

    if(dist[n] == 2139062143){
        cout << "impossible\n";
        return 0;
    }

    queue<tuple<int, int, int>> q;
    q.push({1, a[1], 0});
    v[1] = true;

    int ans = 0;
    while(!q.empty()){
        auto[cur, cnt, d] = q.front();
        q.pop();
        
        if(cur == n) ans = max(ans, cnt);

        for(auto[next, w]: adj[cur]){
            if(dist[next] != d+w) continue;
            q.push({next, cnt+a[next], d+w});
        }
    }

    cout << dist[n] <<" " << ans <<"\n";

    return 0;
}