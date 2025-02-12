#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int p[500000];

int Find(int x)
{
    if(x == p[x]) return x;
    else return p[x] = Find(p[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x!=y) p[y] = x;
}

int main()
{
    FASTIO;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i<n; i++) p[i] = i;
    for(int i = 1; i<=m; i++){
        int a, b; cin >> a >> b;
        if(Find(a) == Find(b)){
            cout << i;
            return 0;
        }
        Union(a, b);
    }
    cout << 0;
    return 0;
}