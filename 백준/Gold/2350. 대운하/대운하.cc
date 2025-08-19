#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m, k;
int p[1'001];
vector<pair<int, pair<int, int>>> edge;
vector<int> cc[1'001];
int ans[1'001][1'001];

int Find(int x)
{
    if(x == p[x]) return x;
    else return p[x] = Find(p[x]);
}

void Union(int x, int y, int w)
{
    x = Find(x);
    y = Find(y);
    if (x == y) return;
    p[x] = y;
    for (int xc : cc[x]){
        for (int yc : cc[y]){
            ans[xc][yc] = w;
            ans[yc][xc] = w;
        }
    }
    for (int xc : cc[x]) cc[y].push_back(xc);
}

bool compare(pair<int, pair<int, int>> fs, pair<int, pair<int,int>> sc)
{
    return fs.first > sc.first;
}

signed main()
{
    FASTIO;
    // memset(ans, 0x7f, sizeof(ans));
    cin >> n >> m >> k;
    for(int i = 1; i<=n; i++){
        p[i] = i;
        cc[i].push_back(i);
    }

    for(int i = 0; i<m; i++){
        int s, e, w;
        cin >> s >> e >> w;
        edge.push_back({w, {s,e}});
    }
    sort(edge.begin(), edge.end(), compare);

    for(auto[w, v]: edge){
        auto[s, e] = v;
        Union(s, e, w);
    }

    for(int i = 0; i<k; i++){
        int s, e;
        cin >> s >> e;
        cout << ans[s][e] <<"\n";
    }
    return 0;
}