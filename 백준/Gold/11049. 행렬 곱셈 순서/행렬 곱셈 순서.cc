#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;
pair<int, int> a[501];

int dp[501][501];

int go(int l, int r)
{
    if(l == r){
        return dp[l][r] = 0;
    }

    if(dp[l][r] != -1) return dp[l][r];

    int &ret = dp[l][r];
    for(int i = l; i<=r; i++){
        int temp = go(l, i)+go(i+1,r)+ a[l].first*a[i].second*a[r].second;
        if(ret == -1) ret = temp;
        else ret = min(ret, temp);
    }
    return ret;
}

signed main()
{
    FASTIO;
    memset(dp, -1, sizeof(dp));

    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i].first >> a[i].second;
    }
    
    cout << go(0, n-1);
    return 0;
}   