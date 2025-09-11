#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int a, b;

void solve()
{
    cin >> a >> b;
    cout << a+b <<"\n";
}

signed main()
{
    FASTIO;
    int _tc; cin >> _tc;
    while(_tc--) solve();
    return 0;
}