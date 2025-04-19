#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, r, q;
vector<int> adj[100'001];
int cnt[100'001];

void dfs(int pre, int x)
{
    if(adj[x].size() == 1 && x!=r){
        cnt[x] = 1;
        return;
    }

    for(int e: adj[x]){
        if(e == pre) continue;
        dfs(x, e);
        cnt[x] += cnt[e];
    }
    cnt[x]++;
}

int main()
{
    FASTIO;
    cin >> n >> r >> q;
    for(int i = 0; i<n-1; i++){
        int s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    dfs(0, r);

    while(q--){
        int e; cin >> e;
        cout <<cnt[e] <<"\n";
    }
    return 0;
}