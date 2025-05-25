#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m, k;
char graph[1002][1002];

int dx[4] = {0, 0 , 1, -1};
int dy[4] = {1, -1 ,0 , 0};

bool v[1002][1002][11];

int main()
{
    FASTIO;
    cin >> n >> m >> k;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin >> graph[i][j];
        }
    }

    queue<pair<pair<int, int>, pair<int,int>>> q;
    q.push({{1,1}, {1,0}});
    while(!q.empty()){
        auto [node, state] = q.front();
        auto [x,y] = node;
        auto [dist, use] = state;
        // cout << dist <<": " <<x << ", " <<y << ", " << use <<"\n";
        if(x == n && y == m){
            cout << dist;
            return 0;
        }
        q.pop();
        for(int i = 0; i<4; i++){
            if(x+dx[i]<1 || x+dx[i]>n || y+dy[i]<1 || y+dy[i]>m) continue;
            if(v[x+dx[i]][y+dy[i]][use]) continue;

            if(graph[x+dx[i]][y+dy[i]] == '1'){
                if(use == k) continue;
                else{
                    q.push({{x+dx[i], y+dy[i]}, {dist+1, use+1}});
                    v[x+dx[i]][y+dy[i]][use] = true;
                }
            }
            else{
                q.push({{x+dx[i], y+dy[i]}, {dist+1, use}});
                v[x+dx[i]][y+dy[i]][use] = true;
            }
        }
    }
    cout << -1;
    return 0;
}