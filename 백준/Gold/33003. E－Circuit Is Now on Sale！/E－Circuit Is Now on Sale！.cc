#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int n, m;
char a[55][55];
int v[55][55];
ll temp[55][55];

ll ans = 0;

signed main()
{
    FASTIO;
    queue<tuple<int, int, ll>> q;

    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin >> a[i][j];
            
            if('0'<= a[i][j] && a[i][j] <='9'){
                q.push({i, j, (ll)(a[i][j]-'0')});
            }
        }
    }


    while(!q.empty()){
        auto[x, y, val] = q.front();
        q.pop();
        
        for(int t = 0; t<4; t++){
            int nx = x+dx[t];
            int ny = y+dy[t];
            
            if(a[nx][ny] == '.' || a[nx][ny] == NULL) continue;

            else if(a[nx][ny] == '#'){
                if(v[nx][ny]) continue;
                
                q.push({nx, ny, val});
                v[nx][ny] = 1;
            }
            else if(a[nx][ny] == 'P'){
                ans = val;
            }
            else{
                if(v[nx][ny] == 0){
                    v[nx][ny]++;
                    temp[nx][ny] = val;
                }
                else if(v[nx][ny] == 1){
                    v[nx][ny]++;

                    if(a[nx][ny] == '+'){
                        q.push({nx, ny, val+temp[nx][ny]});
                    }
                    else if(a[nx][ny] == '*'){
                        q.push({nx, ny, val*temp[nx][ny]});
                    }
                    else if(a[nx][ny] == '-'){
                        q.push({nx, ny, abs(val-temp[nx][ny])});
                    }
                    else if(a[nx][ny] == '/'){
                        if(temp[nx][ny] < val) q.push({nx, ny, val/temp[nx][ny]});
                        else q.push({nx, ny, temp[nx][ny]/val});
                    }
                }
                else continue;
            }
        }
    }

    cout << ans;
    return 0;
}