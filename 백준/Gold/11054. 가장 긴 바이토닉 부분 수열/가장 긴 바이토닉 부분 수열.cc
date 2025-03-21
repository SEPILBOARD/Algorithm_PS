#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int a[1001];
int dp[1001][2];

bool climb = true;
int main()
{
    FASTIO
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        dp[a[i]][0] = 1;
        dp[a[i]][1] = 1;
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(a[j]<a[i]){
                dp[a[i]][0] = max(dp[a[i]][0], dp[a[j]][0]+1);
            }
            else if(a[j]>a[i]){
                dp[a[i]][1] = max(dp[a[i]][1], dp[a[j]][1]+1);
                dp[a[i]][1] = max(dp[a[i]][1], dp[a[j]][0]+1);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i<=1001; i++){
        ans = max(ans, dp[i][0]);
        ans = max(ans, dp[i][1]);
    }
    cout << ans;
    return 0;
}