#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int n;
string s;

signed main()
{
    FASTIO;
    cin >> n;
    cin >> s;

    int ans = 1;
    int lidx = 0;
    int ridx = n-1;

    while(lidx <= ridx){
        while(lidx <= ridx && s[lidx] == s[ridx]) ridx--;
        if(lidx > ridx) break;

        ans++;
        while(lidx <= ridx && s[lidx] != s[ridx]) ridx--;
    }

    cout << ans;

    return 0;
}