#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int a[130][130];
int psum[130][130];

int w;
int b;

void dc(int sx, int sy, int ex, int ey)
{
    if(sx == ex && sy == sy){
        if(a[sx][sy] == 1) b++;
        else w++;
        return;
    }
    int cur_sum = psum[ex][ey] - psum[ex][sy-1] - psum[sx-1][ey] + psum[sx-1][sy-1];
    if((ex-sx+1)*(ey-sy+1) == cur_sum){
        b++;
        return;
    }
    else if(cur_sum == 0){
        w++;
        return;
    }
    dc(sx, sy, (sx+ex)/2, (sy+ey)/2);
    dc((sx+ex)/2+1, sy, ex, (sy+ey)/2);
    dc(sx, (sy+ey)/2+1, (sx+ex)/2, ey);
    dc((sx+ex)/2+1, (sy+ey)/2+1, ex, ey);
    
}

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> a[i][j];
            psum[i][j] = psum[i-1][j] + psum[i][j-1] + a[i][j] - psum[i-1][j-1];
        }
    }

    // for(int i = 1; i<=n; i++){
    //     for(int j = 1; j<=n; j++){
    //         cout << psum[i][j] <<" ";
    //     }
    //     cout << "\n";
    // }

    dc(1, 1, n, n);
    cout << w << "\n" << b;
    return 0;
}