#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define INF 2139062143

int n, m, t;
int S, G, H;
vector<pair<int, int>> adj[2'002];
double dist1[2'002];
double dist2[2'002];

void dijk(int s, double* d)
{
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    d[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        auto [w, node] = pq.top();
        pq.pop();
        if(d[node] != w) continue;
        for(auto [nw, next]: adj[node]){
            if(d[next] <= w+nw) continue;
            d[next] = w+nw;
            pq.push({d[next], next});
        }
    }
}

void solve()
{
    int ghw;
    cin >> n >> m >> t;
    cin >> S >> G >> H;
    for(int i = 1; i<=n; i++) adj[i].clear();
    memset(dist1, 0x7f, sizeof(dist1));
    memset(dist2, 0x7f, sizeof(dist2));
    for(int i= 0; i<m; i++){
        int s, e, w;
        cin >> s >>e >> w;
        if((s==G && e==H) || (s==H && e==G)){
            ghw = w;
            continue;
        }
        adj[s].push_back({w, e});
        adj[e].push_back({w, s});
    }

    dijk(S, dist1);
    adj[G].push_back({ghw-0.001, H});
    adj[H].push_back({ghw-0.001, G});
    dijk(S, dist2);

    vector<int> ans;
    for(int i = 0; i<t; i++){
        int dest;
        cin >> dest;
        if(dist1[dest] > dist2[dest]){
            ans.push_back(dest);
        }
    }
    sort(ans.begin(), ans.end());
    // for(int i = 1; i<=n; i++){
    //     cout <<i <<": " <<dist1[i] <<" " <<dist2[i] <<"\n";
    // }

    for(int e: ans) cout << e << " ";
    cout << "\n";
    // cout << dist1[1];
}

int main()
{
    FASTIO;
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}