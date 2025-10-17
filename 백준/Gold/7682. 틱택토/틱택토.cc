#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

string s;

void solve()
{
    int xcnt = 0;
    int ocnt = 0;
    int dcnt = 0;
    bool oflag = false;
    bool xflag = false;

    for(int i = 0; i<9; i++){
        if(s[i] == 'X') xcnt++;
        else if(s[i] == 'O') ocnt++;
        else dcnt++;
    }
    if(xcnt != ocnt && xcnt-1 != ocnt){
        cout << "invalid\n";
        return;
    }

    for(int i = 0; i<9; i+=3){
        if(s[i] == '.') continue;
        if(s[i] == s[i+1] && s[i] == s[i+2]){
            if(s[i] == 'O'){
                if(xflag) {cout << "invalid\n"; return;}
                oflag = true;
            }
            else{
                if(oflag) {cout << "invalid\n"; return;}
                xflag = true;
            }
        }
    }
    for(int i = 0; i<3; i++){
        if(s[i] == '.') continue;
        if(s[i] == s[i+3] && s[i] == s[i+6]){
            if(s[i] == 'O'){
                if(xflag) {cout << "invalid\n"; return;}
                oflag = true;
            }
            else{
                if(oflag) {cout << "invalid\n"; return;}
                xflag = true;
            }
        }
    }
    if(s[0] !='.' && s[0] == s[4] && s[0] == s[8]){
        if(s[0] == 'O'){
            if(xflag) {cout << "invalid\n"; return;}
            oflag = true;
        }
        else{
            if(oflag) {cout << "invalid\n"; return;}
            xflag = true;
        }
    }
    if(s[2] !='.' && s[2] == s[4] && s[2] == s[6]){
        if(s[2] == 'O'){
            if(xflag) {cout << "invalid\n"; return;}
            oflag = true;
        }
        else{
            if(oflag) {cout << "invalid\n"; return;}
            xflag = true;
        }
    }

    if(oflag){
        if(xcnt == ocnt) cout << "valid\n";
        else cout << "invalid\n";
        return;
    }
    if(xflag){
        if(xcnt-1 == ocnt) cout << "valid\n";
        else cout << "invalid\n";
        return;
    }

    if(dcnt == 0){
        cout << "valid\n";
        return;
    }

    cout << "invalid\n";
}

signed main()
{
    FASTIO;
    cin >> s;
    while(s != "end"){
        solve();
        cin >> s;
    }
    return 0;
}