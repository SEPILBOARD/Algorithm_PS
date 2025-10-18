#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

struct Point
{
    int x, y;
};

inline int dist(Point a, Point b) { return abs(b.x-a.x) + abs(b.y-a.y); }

int n;
Point pos[105];
int p[105];

int Find(int x)
{
    if(x == p[x]) return x;
    else return p[x] = Find(p[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x != y) p[x] = y;
}

void solve()
{
    cin >> n;
    for(int i = 0; i<=n+1; i++){
        cin >> pos[i].x >> pos[i].y;
        p[i] = i;
    }

    for(int i = 0; i<=n+1; i++){
        for(int j = i+1; j<=n+1; j++){
            if(dist(pos[i], pos[j]) <= 1000) Union(i, j);
        }
    }

    if(Find(0) == Find(n+1)) cout << "happy\n";
    else cout << "sad\n";
}

signed main()
{
    FASTIO;
    int _tc; cin >> _tc;
    while(_tc--) solve();
    return 0;
}