#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, k;
int a[1001];
int dth[1001];
int p[1001];

void solve()
{
    int kidx = 0;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        p[i] = i;
        if(a[i] == k) kidx = i;
    }
    int cur_p = 0;
    dth[0] = 0;

    int idx = 1;
    while(idx<n){
        do{
            p[idx] = cur_p;
            dth[idx] = dth[cur_p]+1;
            idx++;
        }
        while(a[idx-1]+1 == a[idx] && idx<n);
        cur_p++;
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(p[i] != p[kidx] && p[p[i]] == p[p[kidx]] && dth[i] == dth[kidx]) ans++;
    }
    cout << ans <<"\n";
}

int main()
{
    FASTIO;
    while(1){
        cin >> n >> k;
        if(!n) break;
        solve();
    }
    return 0;
}