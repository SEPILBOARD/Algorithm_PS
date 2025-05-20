#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

pair<int, int> dp[41];

int main()
{
    FASTIO;
    dp[0] = {1, 0};
    dp[1] = {0, 1};
    for(int i = 2; i<=40; i++){
        dp[i] = {dp[i-1].first+dp[i-2].first, dp[i-1].second+dp[i-2].second};
    }
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << dp[n].first << " " << dp[n].second <<"\n";
    }
    return 0;
}