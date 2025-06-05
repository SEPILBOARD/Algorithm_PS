#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define INFLL 9187201950435737471

int n, m;
vector<tuple<int, int, int>> graph;
long long int dist[501];

bool bf(int s)
{
    memset(dist, 0x7f, sizeof(dist));
    dist[s] = 0;
    for(int i = 0; i<n; i++){
        for(auto [s, e, w]: graph){
            if(dist[s] == INFLL) continue;;
            if(dist[e] > dist[s]+w){
                dist[e] = dist[s]+w;
                if(i==n-1) return false;
            }
        }
    }
    return true;
}

int main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int s, e, w;
        cin >> s >> e >> w;
        graph.push_back({s, e, w});
    }
    if(bf(1)){
        for(int i = 2; i<=n; i++){
            if(dist[i] == INFLL) cout << "-1\n";
            else cout << dist[i] <<"\n";
        }
    }
    else{
        cout << "-1";
    }
    return 0;
}