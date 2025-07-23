#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;
int adj[501][501];

signed main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;

        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(adj[i][k] == 0 || adj[k][j] == 0) continue;

                if(adj[i][j]) adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
                else adj[i][j] = adj[i][k]+adj[k][j];
            }
        }
    }
    
    int ans = 0;
    int kb = 987654321;
    for(int i = 1; i<=n; i++){
        int cur_kb = 0;
        for(int j = 1; j<=n; j++){
            cur_kb += adj[i][j];
        }
        if(cur_kb < kb){
            ans = i;
            kb = cur_kb;
        }
    }

    cout << ans;
    return 0;
}