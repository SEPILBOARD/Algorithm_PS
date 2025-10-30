#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;
int sum, mx;

signed main()
{
    FASTIO;
    
    cin >> n;
    int a = 0;
    for(int i = 0; i<n; i++){
        cin >> a;
        mx = max(mx, a);
        sum += a;
    }

    cout << sum-mx + (n-1)*mx;    
    return 0;
}