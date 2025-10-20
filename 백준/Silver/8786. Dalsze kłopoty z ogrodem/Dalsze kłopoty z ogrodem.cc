#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int _tc;
int n;
int a[1'000'005];

int s, ans;

signed main()
{
    FASTIO;
    cin >> _tc;
    for(int t = 0; t<_tc; t++){
        cin >> n;
        for(int i = 0; i<n; i++) cin >> a[i];

        ans = 0;
        for(int i = 0; i<n; i++){
            if(a[i] == 0) continue;
            s = 32-__builtin_clz(a[i]);
            ans += s;
            a[i+1] >>= s;
            a[i+2] >>= s;
        }

        cout << ans <<"\n";
    }
    return 0;
}