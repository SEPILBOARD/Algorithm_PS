#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define LINF 9187201950435737471

int n, m ,w;
vector<tuple<int, int, int>> graph;
long long int dist[501];

bool bf(int s)
{
    dist[s] = 0;
    for(int i = 0; i<n; i++){
        for(auto [s, e, t] : graph){
            // if(dist[s] == LINF) continue;
            if(dist[e] > dist[s]+t){
                dist[e] = dist[s]+t;
                if(i==n-1) return false;
            }
        }
    }
    return true;
}

void solve()
{
    graph.clear();

    cin >> n >> m >> w;
    for(int i = 0; i<=n; i++) dist[i] = 987654321;
    
    for(int i = 0; i<m; i++){
        int s, e, t;
        cin >> s >> e >> t;
        graph.push_back({s, e, t});
        graph.push_back({e, s, t});
    }
    for(int i = 0; i<w; i++){
        int s, e, t;
        cin >> s >> e >> t;
        graph.push_back({s, e, -t});
    }

    if(bf(1)) cout << "NO\n";
    else cout << "YES\n";
}

int main()
{
    FASTIO;
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}