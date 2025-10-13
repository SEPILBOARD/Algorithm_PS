#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int n;
pair<int, int> a[100'001];

void solve()
{
    cin >> n;
    for(int i = 0; i<n; i++) cin >> a[i].first >> a[i].second;

    sort(a, a+n);

    int cur = a[0].second;
    int ans = 1;
    for(int i = 1; i<n; i++){
        if(cur > a[i].second){
            cur = a[i].second;
            ans++;
        }
    }
    
    cout << ans <<"\n";
}

signed main()
{
    FASTIO;
    int _tc; cin >> _tc;
    while(_tc--) solve();
    return 0;
}