#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;
int ans[9];

void bt(int cnt)
{
    if(cnt == m){
        for(int i = 0; i<m; i++)
            cout << ans[i] <<" ";
        cout << "\n";
        return;
    }

    for(int i = 1; i<=n; i++){
        ans[cnt]=i;
        bt(cnt+1);
    }
}

int main()
{
    FASTIO;
    cin >> n >> m;
    bt(0);
    return 0;
}