#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m, b;
int a[501][501];

signed main()
{
    FASTIO;
    cin >> n >> m >> b;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> a[i][j];
        }
    }

    int anst = 1e+9;
    int ansh = 0;
    for(int h = 0; h<=b/(m*n)+260; h++){
        int curb = b;
        int t = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(a[i][j] > h){
                    t += 2*(a[i][j]-h);
                    curb += a[i][j]-h;
                }
                else if(a[i][j] < h){
                    t += h-a[i][j];
                    curb -= h-a[i][j];
                }
            }
        }

        if(curb < 0) continue;

        if(anst >= t){
            anst = t;
            ansh = h;
        }
    }
    cout << anst << " " << ansh;
    return 0;
}