#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define ll long long int

string s;
int k;
int table[500'001];

signed main()
{
    FASTIO;
    cin >> s >> k;
    
    int n = s.size();
    for(int i = 1, j = 0; i<n; i++){
        while(j>0 && s[i] != s[j]) j = table[j-1];
        if(s[i] == s[j]) table[i] = ++j;
    }

    // n*k - t(k-1)
    ll ans = (n-table[n-1])*(ll)k + table[n-1];
    cout << ans;
    return 0;
}