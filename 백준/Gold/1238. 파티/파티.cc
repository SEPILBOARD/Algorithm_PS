#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;
#define INF 1e+9

int n, m, X;
vector<pair<int, int>> adj[1'001][2];
int dist[1'001][2];

void dijk(int rvs)
{
    for(int i = 1; i<=n; i++){
        dist[i][rvs] = INF;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[X][rvs] = 0;
    pq.push({0, X});
    while(!pq.empty()){
        auto[d, cur] = pq.top();
        pq.pop();
        if(dist[cur][rvs] != d) continue;
        for(auto[nxt, nw]: adj[cur][rvs]){
            if(d+nw>=dist[nxt][rvs]) continue;
            dist[nxt][rvs] = d+nw;
            pq.push({d+nw, nxt});
        }
    }
}

signed main()
{
    FASTIO;
    cin >> n >> m >> X;

    for(int i = 0; i<m; i++){
        int x, y, w;
        cin >> x >> y >> w;

        adj[x][0].push_back({y, w});
        adj[y][1].push_back({x, w});
    }

    dijk(0);
    dijk(1);

    int ans = 0;
    for(int i = 1; i<=n; i++){
        ans = max(ans, dist[i][0]+dist[i][1]);
    }
    cout << ans;
    return 0;
}