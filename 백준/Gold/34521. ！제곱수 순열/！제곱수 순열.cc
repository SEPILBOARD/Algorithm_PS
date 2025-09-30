#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;
set<int> sq;
int a[1'000'001];

void solve()
{
    cin >> n;
    for(int i = 1; i<=n; i++){
        a[i] = i;
        if(sq.count(a[i]+a[i-1])){
            swap(a[i-1], a[i-2]);
        }
    }

    for(int i = 1; i<=n; i++) cout << a[i] <<" ";
    cout << "\n";
}

signed main()
{
    FASTIO;
    for(int i = 2; i<=1'500; i++){
        sq.insert(i*i);
    }

    int _tc; cin >> _tc;
    while(_tc--) solve();
    return 0;
}