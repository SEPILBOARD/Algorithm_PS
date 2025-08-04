#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int a[20'001];
bool v[20'001];
vector<int> cyc;

void dfs(int x, int cnt)
{
    if(v[a[x]]) cyc.push_back(cnt);
    else{
        v[a[x]] = true;
        dfs(a[x], cnt+1);
    }
}

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> a[i];

    for(int i = 1; i<=n; i++)
        if(!v[i]){
            v[i] = true;
            dfs(i, 1);
        }

    int ans = 1;
    for(int e: cyc){
        int gcd = __gcd(ans, e);
        ans = ans/gcd * e;
    }
    
    cout << ans;
    return 0;
}