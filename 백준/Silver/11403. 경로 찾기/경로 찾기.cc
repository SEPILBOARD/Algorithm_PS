#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int g[101][101];

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> g[i][j];
        }
    }

    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(g[i][k] == 0 || g[k][j] == 0) continue;

                g[i][j] = 1;
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}