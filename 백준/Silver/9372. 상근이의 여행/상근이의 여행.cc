#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    int a, b;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
    }

    cout << n-1 << "\n";
}

int main()
{
    FASTIO;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}