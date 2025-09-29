#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

char me;
char a[3][3];

bool isWin(char m)
{
    if(a[0][0]==m && a[1][1]==m && a[2][2]==m) return true;
    if(a[0][2]==m && a[1][1]==m && a[2][0]==m) return true;
    for(int i = 0; i<3; i++){
        if(a[i][0]==m && a[i][1]==m && a[i][2]==m) return true;
        if(a[0][i]==m && a[1][i]==m && a[2][i]==m) return true;
    }
    return false;
}

void solve()
{
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            cin >> a[i][j];
        }
    }
    cin >> me;

    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(a[i][j] != '-') continue;

            a[i][j] = me;
            if(isWin(me)){
                for(int i = 0; i<3; i++){
                    for(int j = 0; j<3; j++){
                        cout << a[i][j];
                    }
                    cout << "\n";
                }
                return;
            }
            a[i][j] = '-';
        }
    }
}

signed main()
{
    FASTIO;
    int t; cin >> t;
    for(int i = 1; i<=t; i++){
        cout << "Case " << i <<": \n";
        solve();
    } 
    return 0;
}