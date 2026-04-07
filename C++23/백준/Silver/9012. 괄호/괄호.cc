#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

string s;

void solve()
{
    cin >> s;

    stack<char> stk;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '('){
            stk.push(s[i]);
        }
        else if(s[i] ==')'){
            if(stk.empty()){
                cout << "NO\n";
                return;
            }
            else{
                stk.pop();
            }
        }
    } 

    if(!stk.empty()) cout << "NO\n";
    else cout <<"YES\n";
}

signed main()
{
    FASTIO;

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}