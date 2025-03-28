#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

int n, k, ans;
map<int, int> m;

signed main()
{
    FASTIO;
    cin >> n >> k;
    for(int i = 0; i<n; i++){
        int x, y; cin >> x >> y;
        m[y-k*x]++;
    }

    for(auto e: m){
        ans += e.second*(e.second-1);
    }
    cout << ans;
    return 0;
}

/*
y1-y2 = k(x1-x2)
y1-y2 = kx1 - kx2
y1 - kx1 = y2 - kx2
*/