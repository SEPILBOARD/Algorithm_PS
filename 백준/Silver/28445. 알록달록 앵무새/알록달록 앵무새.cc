#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

string coler;
set<string> s;

signed main()
{
    FASTIO;
    
    for(int i = 0; i<4; i++){
        cin >> coler;
        s.insert(coler);
    }

    for(string c1 : s){
        for(string c2 : s){
            cout << c1 << " " << c2 <<"\n";
        }
    }
    return 0;
}