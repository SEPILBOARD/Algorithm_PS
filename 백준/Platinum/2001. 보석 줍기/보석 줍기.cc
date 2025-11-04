#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, m, k;
vector<pair<int, int>> adj[101];
int a[15];

int v[101];
int mw[101];

signed main()
{
    FASTIO;
    cin >> n >> m >> k;
    for(int i = 0; i<k; i++){
        cin >> a[i];
    }
    for(int i = 0; i<m; i++){
        int b, c, w;
        cin >> b >> c >> w;
        adj[b].push_back({w, c});
        adj[c].push_back({w, b});
    }

    for(int i = 1; i<=n; i++){
        sort(adj[i].begin(), adj[i].end(), greater<>());
    }

    queue<pair<int, int>> q;
    q.push({1, 1e+9});
    mw[1] = 1e+9;

    while(!q.empty()){
        auto [cur, w] = q.front();
        q.pop();
        
        for(auto[nw, next]: adj[cur]){
            int tmw = min(w, nw);
            if(mw[next] >= tmw) continue;
            
            mw[next] = tmw;
            q.push({next, mw[next]});
        }
    }
    mw[1] = k;

    vector<int> tmp;
    for(int i = 0; i<k; i++){
        tmp.push_back(mw[a[i]]);
    }
    sort(tmp.begin(), tmp.end());
    int idx = 1;
    for(int e: tmp){
        if(idx>e) continue;
        idx++;
    }

    cout << idx-1;
    
    return 0;
}