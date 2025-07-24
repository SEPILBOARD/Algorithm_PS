#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, m;
int g[1005][1005];
int ans[1005][1005];

queue<pair<pair<int, int>, int>> q;

signed main()
{
    FASTIO;
    memset(ans, -1, sizeof(ans));

    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin >> g[i][j];
            if(g[i][j] == 2){
                q.push({{i, j}, 0});
                g[i][j] = 0;
            }
            else if(g[i][j] == 0) ans[i][j] = 0;
        }
    }

    while(!q.empty()){
        auto[xy, d] = q.front();
        auto[x, y] = xy;
        q.pop();

        ans[x][y] = d;
        for(int i = 0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(g[nx][ny]){
                g[nx][ny] = 0;
                q.push({{nx, ny}, d+1});
            }
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cout << ans[i][j] <<" ";
        }
        cout << "\n";
    }
    return 0;
}