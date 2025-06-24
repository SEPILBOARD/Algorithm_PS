#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define INF 2139062143

int n, m;
int x, y, z;
vector<pair<int, int>> adj[100'001];
int dist[100'001];

void dijk(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    memset(dist, 0x7f, sizeof(dist));
    
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()){
        auto [w, node] = pq.top();
        pq.pop();
        if(w != dist[node]) continue;
        for(auto [nw, next] : adj[node]){
            if(dist[next] <= w+nw) continue;
            dist[next] = w+nw;
            pq.push({dist[next], next});
        }
    }
}

int main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int s, e, w;
        cin >> s >> e >> w;
        adj[s].push_back({w, e});
    }
    cin >> x >> y >> z;

    dijk(x);
    int dist_y = dist[y];
    if(dist_y == INF) cout << "-1 ";
    else{
        dijk(y);
        if(dist[z] == INF) cout << "-1 ";
        else cout << dist_y + dist[z] <<" ";
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    memset(dist, 0x7f, sizeof(dist));
    pq.push({0, x});
    dist[x] = 0;
    while(!pq.empty()){
        auto [w, node] = pq.top();
        pq.pop();
        if(node == y) continue;
        if(w != dist[node]) continue;
        for(auto [nw, next] : adj[node]){
            if(next == y) continue;
            if(dist[next] <= w+nw) continue;
            dist[next] = w+nw;
            pq.push({dist[next], next});
        }
    }
    if(dist[z] == INF) cout << -1;
    else cout << dist[z];
    return 0;
}