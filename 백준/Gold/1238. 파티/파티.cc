#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define INF 2139062143

int n, m, x;
vector<pair<int, int>> adj[1001];
int dist[1002][1002];

void dijk(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s][s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        auto [w, node] = pq.top();
        pq.pop();
        if(dist[s][node] != w) continue;
        for(auto [ew, next] : adj[node]){
            if(dist[s][next] < w+ew) continue;
            pq.push({w+ew, next});
            dist[s][next] = w+ew;
        }
    }
}

int main()
{
    FASTIO;
    memset(dist, 0x7f, sizeof(dist));
    cin >> n >> m >> x;
    for(int i = 0; i<m; i++){
        int s, e, w;
        cin >> s >> e >> w;
        adj[s].push_back({w, e});
    }
    for(int i = 1; i<=n; i++) dijk(i);

    int ans = 0;
    for(int i = 1; i<=n; i++){
        ans = max(ans, dist[i][x] + dist[x][i]);
    }
    cout << ans;
    return 0;
}