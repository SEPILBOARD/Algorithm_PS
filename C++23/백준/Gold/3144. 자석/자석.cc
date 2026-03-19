#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, l;
int a[500'002];
int psum[500'002];

signed main()
{
    FASTIO;
    cin >> n >> l;
    a[0] = -1;
    a[n+1] = -1;
    for(int i = 1; i<=n; i++){
        string s;
        cin >> s;
        if(s[0] == 'N') a[i] = 1;
        
        psum[i] = psum[i-1] + (a[i] != a[i-1]);
    }

    int ans = 1e+9;
    for(int i = l; i<=n; i++){
        // cout << i << ": [" << i-l+1 <<", " << i << "]\n";
        if((a[i]==a[i+1]) || (a[i-l+1]==a[i-l]) ||(a[i-l]!=-1 && a[i+1]!=-1 && a[i-l]!=a[i+1])) continue;
        ans = min(ans, (psum[i]-psum[i-l])/2);
    }
    cout << ans <<"\n";
    
    // for(int i = 1; i<=n; i++) cout << psum[i] <<" ";

    return 0;
}