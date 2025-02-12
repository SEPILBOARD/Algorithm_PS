#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int p[1000001];
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
    if(x > y) p[x] = y;
    else p[y] = x;
}

void solve(int t)
{
    int n, m, k; cin >> n >> k;
    for(int i = 1; i<=n; i++) p[i] = i;
    for(int i = 0; i<k; i++){
        int a, b; cin >> a >> b;
        Union(a, b);
    }

    cout << "Scenario " << t <<":\n";
    cin >> m;
    while(m--){
        int a, b; cin >> a >> b;
        if(Find(a) == Find(b)) cout << "1\n";
        else cout << "0\n";
    }
    cout << "\n";
}

int main()
{
    FASTIO;
    int t; cin >> t;
    for(int i = 1; i<=t; i++) solve(i);
    return 0;
}