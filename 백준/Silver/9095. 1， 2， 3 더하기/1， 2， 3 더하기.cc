#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int dp[13];

void bt(int cur)
{
    if(cur>10) return;
    dp[cur]++;
    for(int i = 1; i<=3; i++){
        bt(cur+i);
    }
}

int main()
{
    FASTIO;
    bt(0);
    int t;
    cin >> t;
    while (t--){
        int e; cin >> e;
        cout << dp[e] <<"\n";
    }
    
    return 0;
}