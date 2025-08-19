#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;
int p[1000001];

int Find(int x)
{
    if( x==p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    if(x<y) p[y] = x;
    else p[x] = y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i<=n; i++){
        p[i] = i;
    }

    for(int i = 0; i<m; i++){
        int q; cin >> q;
        int x, y; 
        if(q){
            cin >> x >> y;
            if(Find(x) == Find(y)) cout << "YES\n";
            else cout << "NO\n";
        }
        else{
            cin >> x >> y;
            Union(x, y);
        }
    }

    return 0;
}