#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int n, q;
int a[300'001];
int psum[300'001];

signed main()
{
    FASTIO;
    cin >> n >> q;
    for(int i = 1; i<=n; i++) cin >> a[i];
    sort(a+1, a+n+1);

    for(int i = 0; i<n; i++){
        psum[i+1] = psum[i]+a[i+1];
    }
    
    int l, r;
    for(int i = 0; i<q; i++){
        cin >> l >> r;
        cout << psum[r]-psum[l-1] <<"\n";
    }
    
    return 0;
}