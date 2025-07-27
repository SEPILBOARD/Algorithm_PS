#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, k;
pair<int, int> vm[300'001];
multiset<int> c;

signed main()
{
    FASTIO;
    cin >> n >> k;
    for(int i = 0; i<n; i++){
        int m, v;
        cin >> m >> v;
        vm[i] = {v, m};
    }
    for(int i = 0; i<k; i++){
        int e; cin >> e;
        c.insert(e);
    }

    sort(vm, vm+n);
    long long int ans = 0;
    for(int i = n-1; i>=0; i--){
        auto it = c.lower_bound(vm[i].second);
        if(it == c.end()) continue;

        ans += vm[i].first;
        c.erase(it);
    }

    cout << ans;
    return 0;
}