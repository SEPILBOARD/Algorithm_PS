#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;
int a[100'001];

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    cin >> m;
    for(int i = 0; i<m; i++){
        int e; cin >> e;
        int idx = lower_bound(a, a+n, e) - a;
        if(idx<n && a[idx] == e) cout << "1\n";
        else cout << "0\n";
    }
    
    return 0;
}