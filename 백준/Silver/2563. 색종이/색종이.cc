#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
bool p[101][101];

int main()
{
    FASTIO;
    cin >> n;
    while(n--){
        int x, y; cin >> x >> y;
        for(int i = x; i<x+10; i++){
            for(int j = y; j<y+10; j++){
                p[i][j] = true;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i<=100; i++){
        for(int j = 0; j<=100; j++){
            if(p[i][j])ans++;
        }
    }
    cout << ans;
    return 0;
}