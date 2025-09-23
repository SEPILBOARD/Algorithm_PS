#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

vector<int> sq;
int n;

int dp[50'001];


signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 1; i*i<=n; i++){
        sq.push_back(i*i);
    }

    memset(dp, 0x7f, sizeof(int)*(n+1));
    dp[0] = 0;
    for(int e: sq){
        dp[e] = 1;
        for(int i = 0; i<e; i++){
            for(int j = 1; i+e*j<=n; j++){
                dp[i+e*j] = min(dp[i+e*j], dp[i]+j);
            }
        }
    }
    // for(int i = 1; i<=n; i++){
    //     cout << i <<": "<< dp[i] <<"\n";
    // }
    cout << dp[n];

    return 0;
}