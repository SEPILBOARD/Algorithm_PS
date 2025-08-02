#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
string s;

int table[1'000'001];

signed main()
{
    FASTIO;
    cin >> n >> s;
    
    int mxt = 0;
    int idx = n-1;

    for(int i = 1, j = 0; i<n; i++){
        while(j>0 && s[i] != s[j]) j = table[j-1];
        if(s[i] == s[j]){
            table[i] = ++j;
            if(mxt <= table[i]){
                mxt = table[i];
                idx = i;
            }
        }
    }

    cout << n-table[n-1];
    return 0;
}