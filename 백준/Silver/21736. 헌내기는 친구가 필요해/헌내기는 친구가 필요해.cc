#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, m;
char a[606][606];
bool v[606][606];

signed main()
{
    FASTIO;
    
    queue<pair<int, int>> q;
    
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'I'){
                q.push({i, j});
                v[i][j] = true;
            }
        }
    }

    int ans = 0;

    while(!q.empty()){
        auto[x, y] = q.front();
        q.pop();

        for(int t = 0; t<4; t++){
            int nx = x+dx[t];
            int ny = y+dy[t];

            if(a[nx][ny] == NULL || a[nx][ny] == 'X' || v[nx][ny]) continue;
            if(a[nx][ny] == 'P') ans++;

            q.push({nx, ny});
            v[nx][ny] = true;
        }
    }

    if(ans) cout << ans;
    else cout << "TT";
    return 0;
}