#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m, a;
long long int sum;

signed main()
{
    FASTIO;
    int mn = 1e+9 + 1;

    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> a;
            mn = min(mn, a);
            sum += a;
        }
    }

    cout << sum - mn;

    return 0;
}