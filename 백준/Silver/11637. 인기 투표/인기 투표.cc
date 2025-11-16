#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int n;

void solve()
{
    int r = 0;
    int mxcnt = 0;
    int sum = 0;

    cin >> n;

    for(int i = 1; i<=n; i++){
        int x;
        cin >> x;
        sum += x;

        if(mxcnt < x){
            mxcnt = x;
            r = i;
        }
        else if(mxcnt == x){
            r = n+1;
        }
    }

    if(r == n+1) cout << "no winner\n";
    else{
        if(sum/2 < mxcnt) cout << "majority winner " << r <<"\n";
        else cout << "minority winner " << r <<"\n";
    }
}

signed main()
{
    FASTIO;
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}