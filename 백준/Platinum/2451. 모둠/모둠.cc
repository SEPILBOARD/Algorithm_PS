#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
bool adj[3001][3001];
int cnt[3001][3001];
int dp[3001];
int cut[3001];

int main() {
    FASTIO
    cin >> n;

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        while(x != 0){
            adj[i][x] = true;
            cin >> x;
        }
        for(int j = 1; j <= n; j++){
            cnt[i][j] = cnt[i][j - 1] + adj[i][j];
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cnt[i][j] += cnt[i-1][j];
        }
    }
    
    // for(int i = 1; i<=n; i++){
    //     for(int j = 1; j<=n; j++){
    //         cout << cnt[i][j] <<" ";
    //     }
    //     cout << "\n";
    // }

    memset(dp, 0x7f, sizeof(dp));
    dp[0] = 0;
    dp[1] = 0;

    for(int i = 2; i <= n; i++){
        for(int k = 0; k < i; k++){
            int len = i - k;
            int tcnt = len*(len-1)/2;

            int outscore = cnt[i][k] - cnt[k][k];
            
            int incnt = (cnt[i][i] - 2*outscore - cnt[k][k])/2;
            int inscore = tcnt - incnt;
            // cout <<i << ", " <<k <<": "<<outscore <<"\n";
            // cout <<i << ", " <<k <<": "<<tcnt<<" "<<incnt <<"\n";

            int tscore = dp[k] + inscore + outscore;
            // cout <<i << ", " <<k <<": "<<inscore <<"\n";

            if(dp[i] > tscore){
                dp[i] = tscore;
                // cout <<"~"<<i << ", " <<k <<": "<<dp[i] <<"\n";
                cut[i] = k;
            }
        }
    }

    stack<int> s;
    int idx = n;
    while(idx > 0){
        int prev = cut[idx];
        s.push(idx - prev);
        idx = prev;
    }

    cout << dp[n] << '\n';
    cout << s.size() << " ";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
