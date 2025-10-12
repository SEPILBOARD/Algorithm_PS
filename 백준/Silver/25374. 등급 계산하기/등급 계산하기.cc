#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
// int a[101];
int gidx[10] = {0, 4, 11, 23, 40, 60, 77, 89, 96, 100};
int cnt[101];

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<100; i++){
        int g; cin >> g;
        cnt[g]++;
    }

    int g = 1;
    int cur = 0;
    int bf = 0;
    for(int i = 100; i>=0; i--){
        cur += cnt[i];
        if(gidx[g] <= cur){
            cout << cur-bf <<"\n";
            bf = cur;
            g++;
            if(g == 10) break;
            while(g<9 && gidx[g]<= cur){
                g++;
                cout << "0\n";
            }
        }
    }

    return 0;
}