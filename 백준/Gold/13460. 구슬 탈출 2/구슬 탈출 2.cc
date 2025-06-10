#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

struct Point{
    int x, y;
    bool operator==(Point other){
        return x == other.x && y == other.y;
    }
    bool operator!=(Point other){
        return x != other.x || y != other.y;
    }
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, m;
char graph[11][11];
Point r, b, o;

int ans = 999;

void bt(int cnt)
{
    if(cnt==10) return;

    int rx = r.x;
    int ry = r.y;
    int bx = b.x;
    int by = b.y;

    for(int i = 0; i<4; i++){
        if((i==0 && b.y>r.y) || (i==1 && b.y<r.y) || (i==2 && b.x>r.x) || (i==3 && b.x<r.x)){
            while(graph[b.x+dx[i]][b.y+dy[i]] == '.' && b!=o) b.x += dx[i], b.y += dy[i];
            graph[bx][by] = '.';
            graph[b.x][b.y] = 'B';
            while(graph[r.x+dx[i]][r.y+dy[i]] == '.' && r!=o) r.x += dx[i], r.y += dy[i];
            graph[rx][ry] = '.';
            graph[r.x][r.y] = 'R';
        }
        else{
            while(graph[r.x+dx[i]][r.y+dy[i]] == '.' && r!=o) r.x += dx[i], r.y += dy[i];
            graph[rx][ry] = '.';
            if(r==o) graph[r.x][r.y] = '.';
            else graph[r.x][r.y] = 'R';
            while(graph[b.x+dx[i]][b.y+dy[i]] == '.' && b!=o) b.x += dx[i], b.y += dy[i];
            graph[bx][by] = '.';
            graph[b.x][b.y] = 'B';
        }
        
        if(b==o);
        else if(r==o) ans = min(ans, cnt+1);
        else bt(cnt+1);

        graph[r.x][r.y] = '.';
        graph[rx][ry] = 'R';
        graph[b.x][b.y] = '.';
        graph[bx][by] = 'B';
        r.x = rx;
        r.y = ry;
        b.x = bx;
        b.y = by;
    }
}

int main()
{
    FASTIO;
    cin >> n >> m;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 'B') b.x = i, b.y = j;
            else if(graph[i][j] == 'R') r.x = i, r.y = j;
            else if(graph[i][j] == 'O'){
                graph[i][j] = '.';
                o.x = i, o.y = j;
            }
        }
    }
    bt(0);
    if(ans == 999) cout << -1;
    else cout << ans;
    return 0;
}