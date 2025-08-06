#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, k, w;
int d[1001];
vector<int> adj[1001];
int idg[1001];
int mxt[1001];

void solve()
{
    cin >> n >> k;
    memset(idg, 0, sizeof(int)*(n+1));
    memset(mxt, 0, sizeof(int)*(n+1));
    for(int i = 1; i<=n; i++) adj[i].clear();

    for(int i = 1; i<=n; i++) cin >> d[i];
    for(int i = 0; i<k; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        idg[y]++;
    }
    cin >> w;
    
    queue<int> q;
    for(int i = 1; i<=n; i++){
        if(idg[i] == 0){
            mxt[i] = 0;
            q.push(i);
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        if(cur == w){
            cout << mxt[w] + d[w] <<"\n";
            return;
        }
        
        for(int e: adj[cur]){
            idg[e]--;
            mxt[e] = max(mxt[e], mxt[cur] + d[cur]);
            if(idg[e] == 0){
                q.push(e);
            }
        }
    }
    
}

signed main()
{
    FASTIO;
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}