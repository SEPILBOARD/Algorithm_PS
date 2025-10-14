#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

struct Gear
{
    int a[10];
    int idx = 0;

    int l(){ return a[(idx-2+8)%8]; }
    int r(){ return a[(idx+2)%8]; }
    int top() { return a[idx]; }
};

Gear g[5];

signed main()
{
    FASTIO;
    for(int t = 1; t<=4; t++){
        string s;
        cin >> s;
        for(int i = 0; i<8; i++){
            g[t].a[i] = s[i]-'0';
        }
    }
    int k;
    cin >> k;

    while(k--){
        int i, r;
        cin >> i >> r;
        
        int er[5] = {0, };
        er[i] = r;

        int lidx = i-1;
        int ridx = i+1;
        while(lidx>0 && g[lidx].r() != g[lidx+1].l()){
            if(er[lidx+1] == -1) er[lidx] = 1;
            else er[lidx] = -1;
            lidx--;
        }
        while(ridx<=4 && g[ridx].l() != g[ridx-1].r()){
            if(er[ridx-1] == -1) er[ridx] = 1;
            else er[ridx] = -1;
            ridx++;
        }

        for(int j = 1; j<= 4; j++){
            g[j].idx = (g[j].idx-er[j]+8)%8;
        }
    }

    int ans = 0;
    for(int i = 1; i<=4; i++){
        ans ^= (g[i].top())<<(i-1);
    }
    
    cout << ans;
    return 0;
}