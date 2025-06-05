#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int V, E;
int dist[20'001];
vector<pair<int, int>> adj[20'001];

void dijkstra(int s)
{
    memset(dist, 0x7f, sizeof(dist));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        auto [w, node] = pq.top();
        pq.pop();
        if(dist[node] != w) continue;
        for(auto [nw, next]: adj[node]){
            if(dist[next] <= w+nw) continue;
            dist[next] = w+nw;
            pq.push({dist[next], next});
        }
    }
}

int main()
{
    FASTIO;
    cin >> V >> E;
    int s; cin >> s;
    for(int i = 0; i<E; i++){
        int s, e, w;
        cin >> s >> e >> w;
        adj[s].push_back({w, e});
    }
    dijkstra(s);
    for(int i = 1; i<=V; i++){
        if(dist[i] == 2139062143) cout << "INF\n";
        else cout << dist[i] <<"\n";
    }
    return 0;
}