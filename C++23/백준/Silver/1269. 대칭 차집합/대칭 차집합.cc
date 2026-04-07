#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, m;
set<int> a;

signed main()
{
    FASTIO;
    
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        a.insert(x);
    }

    int cnt = 0;
    for(int i = 0; i<m; i++){
        int x;
        cin >> x;
        if(a.count(x)) cnt++;
    }

    cout << n+m-2*cnt;

    return 0;
}