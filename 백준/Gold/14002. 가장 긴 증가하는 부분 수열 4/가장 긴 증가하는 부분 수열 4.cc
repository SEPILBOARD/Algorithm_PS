#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int a[1001];
int dp[1001];
int len[1001];
stack<int> s;

int main()
{
    FASTIO
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        dp[a[i]] = 1;
        len[i] = 1;
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(a[j]<a[i]){
                if(dp[a[i]]<=dp[a[j]]+1){
                    dp[a[i]] = dp[a[j]]+1;
                    len[i] = len[j]+1;
                }
            }
        }
    }
    int ans = 0;
    int idx = 0;
    for(int i = 0; i<n; i++){
        ans = max(ans, dp[a[i]]);
    }
    cout << ans <<"\n";
    
    int cur_len = ans;
    for(int i = n-1; i>=0; i--){
        if(cur_len != len[i]) continue;
        s.push(i);
        cur_len --;
    }
    while(!s.empty()){
        cout << a[s.top()] <<" ";
        s.pop();
    }
    return 0;
}