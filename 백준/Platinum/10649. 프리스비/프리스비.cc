#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int
#define INF 9'223'372'036'854'775'807

int n, h;
tuple<int, int, int> c[21];

bool compare(tuple<int, int, int> fs, tuple<int, int, int> sc)
{
    auto [fh, fw, fp] = fs;
    auto [sh, sw, sp] = sc;
    
    return fp-sw > sp-fw;
    // if(fp-sw>=0 && sp-fw>=0){
    //     if(fw == sw) return fp > sp;
    //     return fw > sw;
    // }
    // else if(fp-sw>=0){
    //     return true;
    // }
    // else if(sp-fw>=0){
    //     return false;
    // }
    // else{
    //     if(fw == sw) return fp > sp;
    //     return fw>sw; 
    // }
}

signed main()
{
    FASTIO;
    cin >> n >> h;
    for(int i = 0; i<n; i++){
        int eh, ew, ep;
        cin >> eh >> ew >> ep;
        c[i] = {eh, ew, ep};
    }
    sort(c, c+n, compare);

    int ans = -1;
    for(int i = 0; i< (1<<n); i++){
        int minp = INF;
        int curh = 0;
        for(int j = 0; j<n; j++){
            if(!(i&(1<<j))) continue;
            auto [ch, cw, cp] = c[j];
            minp = min(minp-cw, cp);
            curh += ch;
        }
        // cout << i<<" " <<bitset<8>(i);
        // cout << ": "  << curh <<", " << minp <<"\n";
        if(curh >= h) ans = max(ans, minp);
    }
    if(ans == -1) cout << "Mark is too tall";
    else cout << ans;

    // cout << "\n";
    // for(int i = 0; i<n; i++){
    //     auto [ch, cw, cp] = c[i];
    //     cout << ch << " " << cw << " " << cp <<"\n";
    // }
    return 0;
}