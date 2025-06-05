#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int tri[401][1001];
int sum[401][1001];

void solve()
{
    // memset(sum, 0, sizeof(sum));
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=2*i-1; j++){
            cin >> tri[i][j];
            sum[i][j] = sum[i][j-1] + tri[i][j];
        }
    }

    int ans = -987654321;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=2*i-1; j++){
            int tsum = tri[i][j];
            ans = max(ans, tsum);
            if(j&1){
                for(int sz = 1; i+sz<=n; sz++){
                    tsum += sum[i+sz][j+2*sz] - sum[i+sz][j-1];
                    ans = max(ans, tsum);
                }
            }
            else if(4<=j && j<=2*(i-1)-1){
                // cout << i <<", " <<j <<"\n";
                for(int sz = 1; j-2*sz>0 && 2*(i-sz)-1>=j; sz++){
                    tsum += sum[i-sz][j] - sum[i-sz][j-2*sz-1];
                    ans = max(ans, tsum);
                }
            }
        }
    }
    cout << ans <<"\n";
}

signed main()
{
    FASTIO;
    cin >> n;
    int tcn = 1;
    while(n){
        cout << tcn++ <<". ";
        solve();
        cin >> n;
    }
    return 0;
}