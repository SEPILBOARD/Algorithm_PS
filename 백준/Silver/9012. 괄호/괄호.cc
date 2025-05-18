#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

void solve()
{
    string s;
    cin >> s;

    int cnt = 0;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '(') cnt++;
        else{
            cnt--;
            if(cnt<0){
                cout <<"NO\n";
                return;
            }
        }
    }
    if(cnt) cout << "NO\n";
    else cout << "YES\n";
}

int main()
{
    FASTIO;
    int t; cin >>t;
    while(t--) solve();
    return 0;
}