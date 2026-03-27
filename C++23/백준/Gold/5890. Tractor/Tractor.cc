#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;
#define MAX 1'000

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int n, sx, sy;
bool v[1'001][1'001];
bool g[1'001][1'001];

signed main()
{
    FASTIO;
    cin >> n >> sx >> sy;
    for(int i = 0; i<n; i++){
        int x, y;
        cin >> x >> y;
        g[x][y] = true;
    }

    deque<tuple<int, int, int>> q;
    q.push_back({sx, sy, 0});
    v[sx][sy] = true;
    while(!q.empty()){
        auto[x, y, d] = q.front();
        q.pop_front();

        if(x == 0 && y == 0){
            cout << d;
            return 0;
        }
        if(x == 0 || y == 0 || MAX<=x || MAX<=y){
            if(g[0][0]) cout << d+1;
            else cout << d;
            return 0;
        }

        for(int t = 0; t<4; t++){
            int nx = x+dx[t];
            int ny = y+dy[t];
            
            if(nx<0 || ny<0 || MAX<nx || MAX<ny) continue;
            if(v[nx][ny]) continue;

            if(g[nx][ny]) q.push_back({nx, ny, d+1});
            else q.push_front({nx, ny, d});
            v[nx][ny] = true;
        }
    }
    
    return 0;
}