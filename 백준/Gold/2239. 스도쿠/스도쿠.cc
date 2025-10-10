#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int a[10][10];
bool rv[10][10];
bool cv[10][10];
bool bv[10][10][10];

bool bt(int i, int j){
    if(i == 9 && j == 0){
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                cout << a[i][j];
            }
            cout << "\n";
        }
        return true;
    }

    if(a[i][j]) return bt((i+(j+1)/9), (j+1)%9);
    else{
        for(int val = 1; val<=9; val++){
            if(rv[i][val] || cv[j][val] || bv[i/3][j/3][val]) continue;
            
            a[i][j] = val;
            rv[i][a[i][j]] = true;
            cv[j][a[i][j]] = true;
            bv[i/3][j/3][a[i][j]] = true;

            bool flag = bt((i+(j+1)/9), (j+1)%9);
            if(flag) return true;

            rv[i][a[i][j]] = false;
            cv[j][a[i][j]] = false;
            bv[i/3][j/3][a[i][j]] = false;
            a[i][j] = 0;
        }
    }
    return false;
}

string s[10];

signed main()
{
    FASTIO;
    for(int i = 0; i<9; i++){
        cin >> s[i];
    }

    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            a[i][j] = s[i][j]-'0';
            rv[i][a[i][j]] = true;
            cv[j][a[i][j]] = true;
            bv[i/3][j/3][a[i][j]] = true;
        }
    }
    
    bt(0, 0);

    return 0;
}