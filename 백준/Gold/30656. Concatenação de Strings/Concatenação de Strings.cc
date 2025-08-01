#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

string r, s;

vector<int> makeTable(string pattern)
{
    int n = pattern.size();
    vector<int> table(n, 0);
    for(int i = 1, j = 0; i<n; i++){
        while(j>0 && pattern[i] != pattern[j]) j = table[j-1];
        if(pattern[i] == pattern[j]) table[i] = ++j;
    }

    return table;
}

void solve()
{
    int n = r.size();
    int m = s.size();

    vector<int> table1 = makeTable(r);
    vector<int> table2 = makeTable(s);

    int rt = n-table1[n-1];
    int st = m-table2[m-1];
    if(rt != st){
        cout << "NAO\n";
        return;
    }
    
    for(int i = 0; i<rt; i++){
        if(r[i] != s[i]){
            cout << "NAO\n";
            return;
        }
    }

    if(n%rt || m%rt){
        cout << "NAO\n";
        return;
    }
    n /= rt;
    m /= rt;
    int gcd = __gcd(n, m);
    cout << m/gcd <<" " <<n/gcd <<"\n";
}

signed main()
{
    FASTIO;
    cin >> r >> s;
    while(r != "#"){
        solve();
        cin >> r >> s;
    }
    return 0;
}