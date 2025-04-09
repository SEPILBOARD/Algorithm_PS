#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, k;
map<int, int> m;

signed main()
{
    FASTIO;
    cin >> n >> k;
    int psum = 0;
    long long int ans =0;
    for(int i = 0; i<n; i++){
        int e; cin >> e;
        psum += e;
        if(psum == k) ans++;
        ans += m[psum-k];
        m[psum]++;
    }
    cout << ans;
    return 0;
}