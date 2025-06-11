#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int p[1001];

int Find(int x)
{
    if(p[x] == x) return x;
    else return p[x] = Find(p[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x != y) p[x] = y;
}

int n, m;

int main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 1; i<=n; i++) p[i] = i;

    for(int i = 0; i<m; i++){
        int x, y;
        cin >> x >> y;
        Union(x, y);
    }

    set<int> s;
    for(int i = 1; i<=n; i++){
        s.insert(Find(i));
    }
    cout << s.size();
    return 0;
}