#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int n, m;
int tmt[1005][1005];

queue<pair<pair<int, int>, int>> q;
int ans = -1;

signed main()
{
    FASTIO;
    memset(tmt, -1, sizeof(tmt));

    cin >> n >> m;
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            cin >> tmt[i][j];
            if(tmt[i][j] == 1) q.push({{i, j}, 0});
        }
    }

    while(!q.empty()){
        auto[xy, d] = q.front();
        auto[x, y] = xy;
        q.pop();

        ans = d;
        for(int i = 0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(tmt[nx][ny] == 0){
                tmt[nx][ny] = 1;
                q.push({{nx, ny}, d+1});
            }
        }
    }

    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(tmt[i][j] == 0){
                cout << -1;
                return 0;
            }
        }
    }
    cout << ans;
    return 0;
}