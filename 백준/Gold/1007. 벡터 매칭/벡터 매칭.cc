#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr);
using namespace std;

pair<int, int> v[20];
int n;
double ans;

void bt(int idx, int pcnt, int mcnt, int vx, int vy)
{
    if(idx == n){
        ans = min(ans, sqrt(pow((long long int)vx, 2)+ pow((long long int)vy, 2)));
        return;
    }
    
    if(pcnt < n/2) bt(idx+1, pcnt+1, mcnt, vx+v[idx].first, vy+v[idx].second);
    if(mcnt < n/2) bt(idx+1, pcnt, mcnt+1, vx-v[idx].first, vy-v[idx].second);
}


void solve()
{
    ans = 987654321;
    cin >> n;
    for(int i = 0; i<n; i++){
        int x, y; cin >> x >> y;
        v[i] = {x, y};
    }
    bt(0, 0, 0, 0, 0);
    cout << ans <<"\n";
}

signed main()
{
    FASTIO;
    cout << fixed;
	cout.precision(7);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}