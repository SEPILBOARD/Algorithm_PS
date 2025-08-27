#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

string s;

void p1(int n)
{
    for(int i = 1; i<=n; i++){
        cout << "..";
        cout << ((i%3==0)?'*':'#');
        cout << ".";
    }
    cout << ".\n";
}

void p2(int n)
{
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<2; j++){
            cout << '.';
            cout << ((i%3==0)?'*':'#');
        }
    }
    cout << ".\n";
}

void p3(int n)
{
    vector<char> prt(4*n+1);
    prt[0] = '#';
    for(int i = 0; i<n; i++){
        int sidx = 4*i;
        if(i%3==2) prt[sidx] = '*';
        prt[sidx+1] = '.';
        prt[sidx+2] = s[i];
        prt[sidx+3] = '.';
        prt[sidx+4] = ((i%3==2)?'*':'#');
    }
    for(char c: prt) cout << c;
    cout << "\n";
}

signed main()
{
    FASTIO;
    cin >> s;
    int n = s.length();
    p1(n); p2(n); p3(n); p2(n); p1(n);
    return 0;
}