#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int g, q, ans;
int p[100001];

int Find(int x)
{
    if(x == p[x]) return x;
    else return p[x] = Find(p[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    else if(x<y) p[y] = x;
    else p[x] = y;
}

int main()
{
    FASTIO;
    cin >> g >> q;
    for(int i = 0; i<=g; i++) p[i] = i;

    while(q--){
        int e; cin >> e;
        int cg = Find(e);
        if(cg == 0) break;
        ans++;
        Union(cg, cg-1);
    }

    cout << ans;
    return 0;
}