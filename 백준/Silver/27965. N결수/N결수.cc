#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int n, k;
int pw[10];

signed main()
{
    FASTIO;
    cin >> n >> k;

    pw[0] = 1;
    for(int i = 0; i<9; i++){
        pw[i+1] = pw[i]*10;
    }

    ll ans = 0;
    for(int i = 1; i<=n; i++){
        ans = (ans*pw[int(log10(i)+1)]+i)%k;
    }
    cout << ans;
    return 0;
}