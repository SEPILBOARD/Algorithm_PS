#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define INF 2139062143

int n, k;
bool v[100'001];
vector<int> c;
int dp[10'001];

int main()
{
    FASTIO;
    cin >> n >> k;
    c.push_back(-1);
    for(int i = 0; i<n; i++){
        int e; cin >> e;
        if(v[e]) continue;
        v[e] = true;
        c.push_back(e);
    }

    memset(dp, 0x7f, sizeof(dp));
    dp[0] = 0;
    n = c.size()-1;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j+c[i]<=k; j++){
            dp[j+c[i]] = min(dp[j+c[i]], dp[j]+1);
        }
    }

    cout << (dp[k]==INF ?-1:dp[k]);
    return 0;
}