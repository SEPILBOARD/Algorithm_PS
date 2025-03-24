#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

int n;
pair<int, int> p[100001];

bool compare(pair<int, int> fs, pair<int, int> sc)
{
    return fs.first * sc.second < sc.first*fs.second;
}

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<=n; i++){
        int t, d; cin >> t >> d;
        p[i] = {t, d};
    }
    sort(p, p+n, compare);
    int ans = 0;
    int curT = 0;
    for(int i = 0; i<n; i++){
        ans += p[i].second * curT;
        curT += 2*p[i].first;
    }
    cout << ans;
    return 0;
}