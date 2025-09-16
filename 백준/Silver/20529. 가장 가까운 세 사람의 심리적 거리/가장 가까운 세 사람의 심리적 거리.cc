#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int cnt[2][2][2][2];

int tgl(int x, int idx)
{
    return (x&(1<<idx)) != 0;
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        cnt[s[0]=='I'][s[1]=='N'][s[2]=='T'][s[3]=='J']++;
    }

    int ans = 1e+9;
    for(int i = 0; i<(1<<4); i++){
        if(cnt[tgl(i, 3)][tgl(i, 2)][tgl(i, 1)][tgl(i, 0)] == 0) continue;
        for(int j = i; j<(1<<4); j++){
            if(cnt[tgl(j, 3)][tgl(j, 2)][tgl(j, 1)][tgl(j, 0)] == 0) continue;
            for(int k = j; k<(1<<4); k++){
                if(cnt[tgl(k, 3)][tgl(k, 2)][tgl(k, 1)][tgl(k, 0)] == 0) continue;
                
                if(i == j && i == k){
                    if(cnt[tgl(i, 3)][tgl(i, 2)][tgl(i, 1)][tgl(i, 0)] < 3) continue;
                }
                else if(i == j || i == k){
                    if(cnt[tgl(i, 3)][tgl(i, 2)][tgl(i, 1)][tgl(i, 0)] < 2) continue;
                }
                else if(j == k){
                    if(cnt[tgl(j, 3)][tgl(j, 2)][tgl(j, 1)][tgl(j, 0)] < 2) continue;
                }

                int ij = (tgl(i, 3) != tgl(j, 3)) + (tgl(i, 2) != tgl(j, 2)) + (tgl(i, 1) != tgl(j, 1)) + (tgl(i, 0) != tgl(j, 0));
                int jk = (tgl(j, 3) != tgl(k, 3)) + (tgl(j, 2) != tgl(k, 2)) + (tgl(j, 1) != tgl(k, 1)) + (tgl(j, 0) != tgl(k, 0));
                int ki = (tgl(i, 3) != tgl(k, 3)) + (tgl(i, 2) != tgl(k, 2)) + (tgl(i, 1) != tgl(k, 1)) + (tgl(i, 0) != tgl(k, 0));
                
                ans = min(ans, ij+jk+ki);
            }
        }
    }
    cout << ans <<"\n";

    memset(cnt, 0, sizeof(cnt));
}

signed main()
{
    FASTIO;
    int _tc; cin >> _tc;
    while(_tc--) solve();
    return 0;
}