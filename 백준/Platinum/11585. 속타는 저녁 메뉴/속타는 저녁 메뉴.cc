#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
char p[1'000'002];
char s[1'000'002];

vector<int> makeTable(string pattern)
{
    vector<int> table(n, 0);
    for(int i = 1, j = 0; i<n; i++){
        while(j>0 && pattern[i] != pattern[j]) j = table[j-1];
        if(pattern[i] == pattern[j]) table[i] = ++j;
    }

    return table;
}

int KMP(string all, string pattern)
{
    int ans = 0;

    vector<int> table = makeTable(pattern);
    for(int i = 0, j = 0; i<2*n-1; i++){
        while(j>0 && pattern[j] != all[i%n]) j = table[j-1];
        if(pattern[j] == all[i%n]){
            if(j == n-1){
                ans++;
                j = table[j];
            }
            else j++;
        }
    }
    return ans;
}

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++) cin >> p[i];
    for(int i = 0; i<n; i++) cin >> s[i];

    int ans = KMP(s, p);
    int gcd = __gcd(ans, n);
    cout << ans/gcd << "/" << n/gcd;
    return 0;
}