#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int n;
char a[1005][1005];
bool v[1005][1005][4]; //좌 우 상 하

int sx, sy;

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> a[i][j];
            if(a[i][j] == 'R'){
                sx = i;
                sy = j;
            }
        }
    }

    queue<tuple<int, int, int>> q;
    q.push({sx, sy, 0});
    
    while(!q.empty()){
        auto [x, y, d] = q.front();
        q.pop();
        if(a[x][y] == 'K'){
            cout << d;
            return 0;
        }
        
        for(int t = 0; t<4; t++){
            int nx = x;
            int ny = y;
            while(true){
                nx += dx[t];
                ny += dy[t];

                if(a[nx][ny] == NULL || a[nx][ny] == 'B') break;
                if(v[nx][ny][t]) break;

                if(a[nx][ny] == 'W'){
                    q.push({nx, ny, d+1});
                    v[nx][ny][t] = true;
                    break;
                }

                q.push({nx, ny, d+1});
                v[nx][ny][t] = true;
            }
        }
    }
    
    cout << "-1";
    return 0;
}