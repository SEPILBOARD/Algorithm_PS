#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, k;
vector<int> a[11];
int psum[11][2001];
int idx[11];

int dp[12][2001];
int ans = 0;

signed main()
{
    FASTIO;
    cin >> n >> k;
    for(int i = 0; i<n; i++){
        int c, g;
        cin >> c >> g;
        a[g].push_back(c);
    }

    for(int i = 1; i<=10; i++){
        if(a[i].empty()) continue;
        idx[i] = a[i].size();
        sort(a[i].begin(), a[i].end(), greater<int>());
    }

    for(int i = 1; i<=10; i++){
        if(idx[i] == 0) continue;
        psum[i][1] = a[i][0];
        for(int j = 1; j<idx[i]; j++){
            psum[i][j+1] = psum[i][j] + a[i][j];
        }
    }

    for(int i = 1; i<=10; i++){
        for(int j = 0; j<=idx[i]; j++){
            for(int cnt = 0; cnt+j<=k; cnt++){
                dp[i][cnt+j] = max(dp[i][cnt+j], dp[i-1][cnt]+psum[i][j]+max(0, j-1)*j);
                ans = max(ans, dp[i][cnt+j]);
            }
        }
    }

    // for(int i = 1; i<=3; i++){
    //     cout << idx[i] <<" ";
    // }
    // cout << "\n";

    // for(int i = 0; i<=3; i++){
    //     for(int j = 0; j<=k; j++){
    //         cout << dp[i][j] <<" ";
    //     }
    //     cout << "\n";
    // }

    // for(int i = 0; i<=3; i++){
    //     for(int j = 0; j<=idx[i]; j++){
    //         cout << psum[i][j] <<" ";
    //     }
    //     cout << "\n";
    // }
    
    cout << ans;
    return 0;
}