#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, m;
char a[55][55];
bool v[55][55];

int dp[55][55];
int ans = 0;
bool flag = true;

void dfs(int x, int y, int d)
{
    dp[x][y] = d;
    ans = max(ans, d);

    int w = a[x][y]-'0';
    for(int t = 0; t<4; t++){
        int nx = x+w*dx[t];
        int ny = y+w*dy[t];

        if(nx<0 || n<=nx || ny<0 || m<=ny || a[nx][ny] == 'H') continue;

        if(v[nx][ny]){
            flag = false;
            return;
        }
        
        if(dp[nx][ny] <= d){
            v[nx][ny] = true;
            dfs(nx, ny, d+1);
            v[nx][ny] = false;
        }
    }
}

signed main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> a[i][j];
        }
    }

    dfs(0, 0, 1);
    if(flag) cout << ans;
    else cout << "-1";

    return 0;
}