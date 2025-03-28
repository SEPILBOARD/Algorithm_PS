#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int
#define MOD 1000
int n, b;
int a[5][5];
int temp[5][5];
int ans[5][5];

signed main()
{
    FASTIO;
    cin >> n >> b;
    b--;
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cin >> a[i][j];
            a[i][j] %= MOD;
            ans[i][j] = a[i][j];
        }
    }

    while(b){
        if(b&1){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    temp[i][j] =0;
                    for(int k = 0; k<n; k++){
                        temp[i][j] = (temp[i][j] + ans[i][k]*a[k][j]%MOD)%MOD;
                    }
                }
            }
            for(int i = 0; i<n; i++)
                for(int j = 0; j<n; j++)
                    ans[i][j] = temp[i][j];
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                temp[i][j] =0;
                for(int k = 0; k<n; k++){
                    temp[i][j] = (temp[i][j] + a[i][k]*a[k][j]%MOD)%MOD;
                }
            }
        }
        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++)
                a[i][j] = temp[i][j];
        b >>= 1;
    }

    for(int i = 0; i<n; i++){
        for(int j =0; j<n; j++){
            cout << ans[i][j] <<" ";
        }
        cout << "\n";
    }
    return 0;
}
