#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int d[501];
vector<int> adj[501];
int idg[501];

int mxt[501];

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> d[i];
        int a;
        cin >> a;
        while(a != -1){
            adj[a].push_back(i);
            idg[i]++;
            cin >> a;
        }
    }

    queue<int> q;
    for(int i = 1; i<=n; i++){
        if(idg[i] == 0){
            q.push(i);
            mxt[i] = 0;
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int e: adj[cur]){
            mxt[e] = max(mxt[e], mxt[cur] + d[cur]);
            idg[e]--;
            if(idg[e] == 0) q.push(e);
        }
    }

    for(int i = 1; i<=n; i++){
        cout << mxt[i] + d[i] <<"\n";
    }
    return 0;
}