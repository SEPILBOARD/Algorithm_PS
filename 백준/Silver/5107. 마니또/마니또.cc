#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, ans;
bool visited[21];
map<string, int> m;
int a[20];

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
    m.clear();
    memset(visited, false, sizeof(visited));

    int idx = 0;
    for(int i = 0; i<n; i++){
        string s, t; cin >> s >> t;
        if(!m.count(s)) m[s] = idx++;
        if(!m.count(t)) m[t] = idx++;
        a[m[s]] = m[t];
    }

    for(int i = 0; i<n; i++){
        if(visited[i]) {
            continue;
        }
        dfs(i);
    }
    
    cout << ans <<"\n";
}

int main()
{
    FASTIO;
    int cn = 1;
    while(true){
        cin >> n;
        if(!n) break;
        cout << cn++ <<" ";
        solve();
    }
    return 0;
}