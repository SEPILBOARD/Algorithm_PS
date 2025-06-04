#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
string s;
int ans, bcnt, rcnt;
bool r, b;

int main()
{
    FASTIO;
    cin >> n;
    cin >> s;

    if(s[0] == 'B') r = true;
    else b = true;
    for(int i = 0; i<n; i++){
        if(b && s[i] == 'B') bcnt++;
        else if(!b && s[i] == 'R') b = true;

        if(r && s[i] == 'R') rcnt++;
        else if(!r && s[i] == 'B') r = true;
    }
    ans = min(rcnt, bcnt);
    rcnt = 0;
    bcnt = 0;
    r = false;
    b = false;
    if(s[n-1] == 'B') r = true;
    else b = true;
    for(int i = n-1; i>=0; i--){
        if(b && s[i] == 'B') bcnt++;
        else if(!b && s[i] == 'R') b = true;

        if(r && s[i] == 'R') rcnt++;
        else if(!r && s[i] == 'B') r = true;
    }
    ans = min(ans, min(rcnt, bcnt));
    cout << ans;
    return 0;
}