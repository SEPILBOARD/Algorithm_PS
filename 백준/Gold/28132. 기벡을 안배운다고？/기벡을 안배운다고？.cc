#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define doulbe long long doulbe
#define int long long int

map<double, int> m;
int n, xcnt, ycnt, zero;
int ans;

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        int x, y; cin >> x >> y;
        if(x==0 && y==0) zero++;
        else if(x==0) xcnt++;
        else if(y==0) ycnt++;
        else{
            ans += m[(double)x/(double)y];
            m[-(double)y/(double)x]++;
        }
    }
    ans += zero*(n-zero) + zero*(zero-1)/2;
    ans += xcnt*ycnt;
    cout << ans;
    return 0;
}