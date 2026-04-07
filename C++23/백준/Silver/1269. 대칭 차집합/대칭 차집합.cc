#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, m;
bool a[100'000'001];

signed main()
{
    FASTIO;
    
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        a[x] = true;
    }

    int cnt = 0;
    for(int i = 0; i<m; i++){
        int x;
        cin >> x;
        if(a[x]) cnt++;
    }

    cout << n+m-2*cnt;

    return 0;
}