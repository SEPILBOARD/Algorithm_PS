#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;
int a[9];
int ans[9];

void bt(int idx, int cnt)
{
    if(cnt == m){
        for(int i = 0; i<m; i++)
            cout << ans[i] <<" ";
        cout << "\n";
        return;
    }

    for(int i = idx+1; i<n; i++){
        if(i!=0)
        if(a[i-1]==a[i]) continue;
        ans[cnt]=a[i];
        bt(i, cnt+1);
    }
}

int main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    bt(-1, 0);
    return 0;
}