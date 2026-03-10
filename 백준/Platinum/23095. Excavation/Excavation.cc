#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int dx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[8] = {-1, 1, 0, 0, -1, 1, -1 ,1};

int ndx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int ndy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};


int n;
char typ;
char a[101][101];

vector<int> node;
vector<int> adj[10'001];

inline bool isIn(int x, int y){
    return (0<=x && x<n && 0<=y && y<n);
}

void push_adj(int cur)
{
    int x = cur/n;
    int y = cur%n;

    if(typ == 'K'){
        for(int t = 0; t<8; t++){
            int nx = x+dx[t];
            int ny = y+dy[t];
            if(!isIn(nx, ny)) continue;

            if(a[nx][ny] !='.'){
                adj[cur].push_back(n*nx+ny);
            }
        }
    }
    else if(typ == 'N'){
        for(int t = 0; t<8; t++){
            int nx = x+ndx[t];
            int ny = y+ndy[t];
            if(!isIn(nx, ny)) continue;

            if(a[nx][ny] !='.'){
                adj[cur].push_back(n*nx+ny);
            }
        }
    }
    else if(typ == 'R'){
        for(int t = 0; t<4; t++){
            int nx = x+dx[t];
            int ny = y+dy[t];
            while(isIn(nx, ny)){
                if(a[nx][ny] !='.'){
                    adj[cur].push_back(n*nx+ny);
                }
                nx += dx[t];
                ny += dy[t];
            }
        }
    }
    else if(typ == 'B'){
        for(int t = 4; t<8; t++){
            int nx = x+dx[t];
            int ny = y+dy[t];
            while(isIn(nx, ny)){
                if(a[nx][ny] !='.'){
                    adj[cur].push_back(n*nx+ny);
                }
                nx += dx[t];
                ny += dy[t];
            }
        }
    }
    else if(typ == 'Q'){
        for(int t = 0; t<8; t++){
            int nx = x+dx[t];
            int ny = y+dy[t];
            while(isIn(nx, ny)){
                if(a[nx][ny] !='.'){
                    adj[cur].push_back(n*nx+ny);
                }
                nx += dx[t];
                ny += dy[t];
            }
        }
    }
    else{
        assert(false);
    }
}

vector<int> dfstree[10'001];
int idg[10'001];
bool v[10'001];

int cnt = 0;

void dfs(int cur)
{
    v[cur] = true;
    cnt++;

    for(int nxt: adj[cur]){
        if(v[nxt]) continue;

        // cout << nxt/n <<"," <<nxt%n <<"->" <<cur/n <<"," <<cur%n <<"\n";

        dfstree[nxt].push_back(cur);
        idg[cur]++;
        dfs(nxt);
    }
}

signed main()
{
    FASTIO;
    cin >> n >> typ;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> a[i][j];
            if(a[i][j] != '.') node.push_back(n*i+j);
        }
    }
    
    for(int cur: node){
        push_adj(cur);
    }

    dfs(node[0]);
    if(cnt != node.size()){
        cout << "NO\n";
        return 0;
    }

    queue<int> q;
    for(int cur: node){
        if(idg[cur] == 0){
            q.push(cur);
        }
    }

    // for(int cur: node){
    //     cout << cur/n+1 <<"," <<cur%n+1 <<": ";
    //     cout <<idg[cur] <<"\n";
    // }
    
    cout << "YES\n";
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int nxt: dfstree[cur]){
            cout << cur/n+1 <<" " << cur%n+1 <<" " <<nxt/n+1 <<" " <<nxt%n+1 <<"\n";
            if(--idg[nxt]) continue;
            q.push(nxt);

        }
    }

    return 0;
}