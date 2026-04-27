#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

struct DJS
{
    int n;
    vector<int> p;
    vector<int> s;
    
    DJS(int _n)
    {
        this->n = _n;
        p.resize(n+1);
        s.resize(n+1, 1);
        for(int i = 1; i<=n; i++){
            p[i] = i;
        }
    }

    int Find(int x)
    {
        if(p[x] == x) return x;
        else return p[x] = Find(p[x]);
    }

    void Union(int x, int y)
    {
        x = Find(x);
        y = Find(y);

        if(x!=y){
            p[x] = y;
            s[y] += s[x];
            s[x] = 0;
        }
    }
};

vector<tuple<int, int, int, int>> edges;

signed main()
{
    FASTIO;
    int n, m;
    cin >> n >> m;

    for(int i = 1; i<=m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v, i});
    }

    sort(edges.begin(), edges.end());
    DJS kdjs(n);
    ll sum = 0;
    int mxw = 0;
    for(auto[w, u, v, _]: edges){
        if(kdjs.Find(u) == kdjs.Find(v)) continue;
        
        mxw = max(mxw, w);
        sum += w;
        kdjs.Union(u, v);
    }

    int lo = 0, hi = m;
    while(lo+1<hi){
        int mid = lo+hi>>1;

        auto[w,_,__,___] = edges[mid];
        if(w<=mxw) lo = mid;
        else hi = mid;
    }

    sort(edges.begin(), edges.begin()+hi, greater<>());

    vector<int> ans;
    DJS bdjs(n);
    ll tsum = 0;
    for(int i = 0; i<hi; i++){
        auto[w, u, v, idx] = edges[i];
        
        if(bdjs.Find(u) == bdjs.Find(v)) continue;

        tsum += w;
        bdjs.Union(u, v);
        ans.push_back(idx);

        if(bdjs.s[bdjs.Find(u)] == n) break;
    }

    cout << "NO\n";
    if(bdjs.s[bdjs.Find(1)] != n || tsum == sum){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for(int e: ans) cout << e <<"\n";

    return 0;
}