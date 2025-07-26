#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;
int a[500'001];

signed main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }

    int sidx = 1;
    int ans = 0;
    long long int cur = 0;
    for(int i = 1; i<=n; i++){
        cur += a[i];
        while(cur>m){
            cur -= a[sidx];
            sidx++;
        }
        ans = max(ans, (int)cur);
    }
    
    cout << ans;
    return 0;
}