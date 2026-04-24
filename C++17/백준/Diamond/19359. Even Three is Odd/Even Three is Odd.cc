#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

#define MOD 1000000007
#define int long long int

int w[2001];

signed main()
{
    FASTIO
    int n;
    while(cin >> n){
        vector<vector<int>> dp_p(3, vector<int>(n, 0));
        vector<vector<int>> dp_c(3, vector<int>(n, 0));
        for(int i = 0; i < n; i++) cin >> w[i];

        for(int i = 0; i < n; i++){
            for(int p = 0; p<3; p++){
                dp_p[p][i] = (w[i] * (int)pow(i+1, p)) % MOD;
            }
        }

        for(int idx = 3; idx < n; idx++){
            for(int p = 0; p<3; p++) dp_c[p][0] = 0;
            dp_c[2][0] = dp_p[2][0];
            for(int i = 1; i < n; i++){
                dp_c[2][i] = dp_c[2][i-1];
                for(int p = 0; p<3; p++) dp_c[2][i] = (dp_c[2][i]+ (int)pow(i, 2-p)*dp_p[p][i])%MOD;             
            }

            int temp = 0;
            for(int i = n - 1; i >= 0; i--){
                dp_c[0][i] = (temp + dp_p[1][i]) % MOD;
                dp_c[1][i] = (temp * (i+1) + dp_p[2][i]) % MOD;
                dp_c[2][i] = (temp * (i+1)*(i+1)+ dp_c[2][i]) % MOD;

                for(int k = 0; k < 3; k++){
                    dp_c[k][i] = dp_c[k][i] * w[i] % MOD;
                }
                temp = (temp + dp_p[0][i]) % MOD;
            }
            dp_p = dp_c;
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = (ans + i*i * dp_p[0][i])%MOD;
            ans = (ans + i*dp_p[1][i])%MOD;
            ans = (ans + dp_p[2][i])%MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}
