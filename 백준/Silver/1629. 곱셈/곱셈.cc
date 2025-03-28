#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

int a, b, c;

signed main()
{
    FASTIO;
    cin >> a >> b >> c;
    a %= c;
    int ans = 1;
    while(b){
        if(b&1) ans = ans*a % c;
        a = a*a%c;
        b >>= 1;
    }
    cout  << ans;
    return 0;
}
