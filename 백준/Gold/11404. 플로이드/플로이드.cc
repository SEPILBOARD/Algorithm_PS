#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define INF 2139062143

int n, m;
int adj[101][101];
int dist[101][101];

int main()
{
    FASTIO;
    cin >> n >> m;
    memset(adj, 0x7f, sizeof(adj));
    for(int i = 1; i<=n; i++) adj[i][i] = 0;


    for(int i = 0 ; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b],c);
    }

    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(adj[i][k] == INF || adj[k][j] == INF) continue;
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(adj[i][j] >= INF) cout << "0 ";
            else cout << adj[i][j] <<" ";
        }
        cout << "\n";
    }
    return 0;
}