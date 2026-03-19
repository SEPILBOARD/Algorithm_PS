#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int n, m, T;
bool v[105][105][2];

int gx, gy;

signed main()
{
    FASTIO;
    cin >> n >> m >> T;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            int a; cin >> a;
            if(a == 1){
                v[i][j][0] = true;
            }
            else if(a == 2){
                gx = i;
                gy = j;
            }
        }
    }

    queue<tuple<int, int, int, int>> q;
    q.push({1, 1, 0, 0});
    v[1][1][0] = true;
    
    int ans = T+1;
    while(!q.empty()){
        auto[x, y, s, d] = q.front();
        q.pop();

        if(x == n && y == m){
            ans = min(ans, d);
            continue;
        }

        if(s == 1 || (x == gx && y == gy)){
            for(int t= 0; t<4; t++){
                int nx = x+dx[t];
                int ny = y+dy[t];

                if(nx<1 || ny<1 || n<nx || m<ny) continue;
                if(v[nx][ny][1]) continue;

                q.push({nx, ny, 1, d+1});
                v[nx][ny][1] = true;
            }
        }
        else{
            for(int t= 0; t<4; t++){
                int nx = x+dx[t];
                int ny = y+dy[t];

                if(nx<1 || ny<1 || n<nx || m<ny) continue;
                if(v[nx][ny][0]) continue;

                q.push({nx, ny, 0, d+1});
                v[nx][ny][0] = true;
            }
        }
    }

    if(ans<=T) cout << ans <<"\n";
    else cout << "Fail\n";

    // for(int t = 0; t<2; t++){
    //     for(int i = 1; i<=n; i++){
    //         for(int j = 1; j<=m; j++){
    //             if(v[i][j][t]) cout << "1 ";
    //             else cout << "0 ";
    //         }
    //         cout << "\n";
    //     }
    //     cout << "\n";
    // }

    return 0;
}