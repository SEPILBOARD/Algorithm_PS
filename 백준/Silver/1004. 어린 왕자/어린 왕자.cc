#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int sx, sy, ex, ey, n;
void solve()
{
    cin >> sx >> sy >> ex >> ey;
    cin >> n;
    
    int ans = 0;
    for(int i = 0; i<n; i++){
        int x, y, c;
        cin >> x >> y >> c;
        bool sin = sqrt(pow(x-sx, 2)+pow(y-sy, 2)) < c;
        bool ein = sqrt(pow(x-ex, 2)+pow(y-ey, 2)) < c;

        if((sin && !ein) || (!sin && ein)) ans++;
    }
    cout << ans <<"\n";
}

int main()
{
    FASTIO;
    int t; cin >> t;
    while(t--) solve();    
    return 0;
}