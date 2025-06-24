#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m, p, q;

int a[21][21];
int b[21][21];
int ans[21][21];

int main()
{
    FASTIO;
    cin >> n >> m >> p >> q;
    int tc = 1;
    while(n){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin >> a[i][j];
            }
        }
        for(int i = 0; i<p; i++){
            for(int j = 0; j<q; j++){
                cin >> b[i][j];
            }
        }

        if(m != p){
            cout << "Case #" << tc << ":\nundefined\n";
        }
        else{
            memset(ans, 0, sizeof(ans));
            for(int i = 0; i<n; i++){
                for(int j = 0; j<q; j++){
                    for(int k = 0; k<m; k++){
                        ans[i][j] += a[i][k]*b[k][j];
                    }
                }
            }
            cout << "Case #" << tc << ":\n";
            for(int i = 0; i<n; i++){
                cout << "| ";
                for(int j = 0; j<q; j++){
                    cout << ans[i][j] <<" ";
                }
                cout << "|\n";
            }
        }
        tc++;
        cin >> n >> m >> p >> q;
    }
    return 0;
}