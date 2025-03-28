#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m, k;
int a[100][100], b[100][100];

int main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            cin >> a[i][j];

    cin >> m >> k;
    for(int i = 0; i<m; i++)
        for(int j = 0; j<k; j++)
            cin >> b[i][j];

    for(int i = 0; i<n; i++){
        for(int j = 0; j<k; j++){
            int ans = 0;
            for(int l = 0; l<m; l++)
                ans += a[i][l] * b[l][j];
            cout << ans <<" ";
        }
        cout << "\n";
    }

    return 0;
}