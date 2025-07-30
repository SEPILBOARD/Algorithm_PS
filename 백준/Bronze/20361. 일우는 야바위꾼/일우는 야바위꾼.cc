#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, x, k;

signed main()
{
    FASTIO;
    cin >> n >> x >> k;
    while(k--){
        int a, b; cin >> a >> b;
        if(x == a) x = b;
        else if(x == b) x = a;
    }
    cout << x;
    return 0;
}