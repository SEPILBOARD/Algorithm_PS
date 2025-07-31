#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

string s;

void solve()
{
    int n = s.size();
    vector<int> table(n, 0);

    for(int i = 1, j = 0; i<n; i++){
        while(j>0 && s[i] != s[j]) j = table[j-1];
        if(s[i] == s[j]) table[i] = ++j;
    }

    int r = table[n-1];
    // for(int i = n-2; i>n-r; i--){
    //     if(table[i]-i != r-n+1){
    //         cout << "1\n";
    //         return;
    //     }
    // }
    if(n%(n-r)) cout << "1\n";
    else cout << n/(n-r) <<"\n";
}

signed main()
{
    FASTIO;
    cin >> s;
    while(s != "."){
        solve();
        cin >> s;
    }
    return 0;
}