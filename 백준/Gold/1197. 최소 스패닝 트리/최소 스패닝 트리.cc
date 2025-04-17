#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

int V, E;
vector<pair<int ,pair<int, int>>> edge;

int p[10'001];
int Find(int x)
{
    if(x==p[x]) return x;
    else return p[x] = Find(p[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x!=y) p[x] = y;
}

bool isConnect(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x!=y) return false;
    else return true;
}

signed main()
{
    FASTIO;
    cin >> V >> E;
    for(int i = 1; i<=V; i++) p[i] = i;
    for(int i = 0; i<E; i++){
        int s, e, x; cin >> s >> e >> x;
        edge.push_back({x, {s, e}});
    }
    sort(edge.begin(), edge.end());
    
    int ans = 0;
    for(int i = 0; i<E; i++){
        int s = edge[i].second.first;
        int e = edge[i].second.second;
        if(isConnect(s, e)) continue;
        Union(s, e);
        ans += edge[i].first;
    }

    cout << ans;
    return 0;
}