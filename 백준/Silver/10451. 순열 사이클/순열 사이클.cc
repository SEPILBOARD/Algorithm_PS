#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, ans;
int a[1001];
bool visited[1001];

void dfs(int x)
{
    if(visited[x]){
        ans++;
        return;
    }
    else{
        visited[x] = true;
        dfs(a[x]);
    }
}

void solve()
{
    ans = 0;
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> a[i];
    for(int i = 1; i<=n; i++) visited[i] = false;
    for(int i = 1; i<=n; i++){
        if(visited[i]) continue;
        dfs(i);
    }
    cout << ans <<"\n";
}

int main()
{
    FASTIO;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}