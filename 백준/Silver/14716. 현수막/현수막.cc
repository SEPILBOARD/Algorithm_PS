#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {-1, 1, -1, 0, 1, -1, 0, 1};

int n, m;
int a[255][255];

signed main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin >> a[i][j];
        }
    }

    queue<pair<int, int>> q;
    int ans = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(a[i][j] == 0) continue;

            ans++;
            a[i][j] = 0;
            q.push({i, j});
            while(!q.empty()){
                auto [x, y] = q.front();
                q.pop();
                for(int i = 0; i<8; i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(a[nx][ny] == 0) continue;
                    
                    a[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    cout << ans;
    return 0;
}