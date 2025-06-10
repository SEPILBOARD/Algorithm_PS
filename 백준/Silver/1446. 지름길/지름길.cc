#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, dist;
tuple<int, int, int> a[13];
int dp[10'001];

int main()
{
    FASTIO;
    cin >> n >> dist;
    for(int i = 0; i<n; i++){
        int s, e, w;
        cin >> s >> e >> w;
        a[i] = {s, e, w};
    }
    
    dp[0] = 0;
    int idx = 0;
    for(int d = 1; d<=dist; d++){
        dp[d] = dp[d-1]+1;
        for(int i = 0; i<n; i++){
            auto [s, e, w] = a[i];
            if(e != d) continue;
            dp[d] = min(dp[d], dp[s]+w);
        }
    }
    cout << dp[dist];
    return 0;
}