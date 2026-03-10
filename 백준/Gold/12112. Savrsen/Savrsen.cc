#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int A, B;

ll f[10'000'001];

signed main()
{
    FASTIO;
    cin >> A >> B;
    for(int i = A; i<=B; i++){
        f[i] = i;
    }

    for(int i = 1; i<B; i++){
        for(int cur = i+i; cur<=B; cur+=i){
            f[cur] -= i;
        }
    }

    ll ans = 0ll;
    for(int i = A; i<=B; i++){
        ans += abs(f[i]);
    }
    cout << ans <<"\n";

    return 0;
}