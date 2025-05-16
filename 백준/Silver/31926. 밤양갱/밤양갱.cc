#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int
signed main()
{
    FASTIO;
    int n; cin >> n;
    int ans = 8+2;
    int cnt = 1;
    n--;
    while(n>0){
        ans ++;
        n -= cnt;
        cnt *= 2;
    }
    if(n != 0) ans--;
    cout << ans;
    return 0;
}