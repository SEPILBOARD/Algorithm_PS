#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;
char graph[102][102];

int main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> graph[i][j];
        }
    }

    queue<pair<int, int>> q;
    graph[0][0] = '0';
    q.push({0, 1});
    while(!q.empty()){
        auto e = q.front();
        q.pop();
        if(e.first == n*m-1){
            cout << e.second;
            break;
        }
        // cout << e.first <<": " << q.size() <<"\n";
        int x = e.first/m;
        int y = e.first%m;

        if(x+1<n)
        if(graph[x+1][y] == '1'){
            graph[x+1][y] = '0';
            q.push({(x+1)*m+y, e.second+1});
        }
        if(x-1>=0)
        if(graph[x-1][y] == '1'){
            graph[x-1][y] = '0';
            q.push({(x-1)*m+y, e.second+1});
        }
        if(y+1<m)
        if(graph[x][y+1] == '1'){
            graph[x][y+1] = '0';
            q.push({x*m+y+1, e.second+1});
        }
        if(y-1>=0)
        if(graph[x][y-1] == '1'){
            graph[x][y-1] = '0';
            q.push({x*m+y-1, e.second+1});
        }
    }
    return 0;
}