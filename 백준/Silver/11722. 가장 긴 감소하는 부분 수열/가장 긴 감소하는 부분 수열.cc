#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int a[1001];
int dp[1001];

int main()
{
    FASTIO
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        dp[a[i]] = 1;
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(a[j]>a[i]) dp[a[i]] = max(dp[a[i]], dp[a[j]]+1);
        }
    }
    int ans = 0;
    for(int i = 1; i<=1001; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}