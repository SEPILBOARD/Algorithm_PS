#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;
int N[1025][1025];

int main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            int e; cin >> e;
            N[i][j] = e + N[i-1][j] + N[i][j-1] - N[i-1][j-1];
        }
    }
    while(m--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << N[x2][y2] - N[x1-1][y2] - N[x2][y1-1] + N[x1-1][y1-1] << "\n";
    }
    return 0;
}