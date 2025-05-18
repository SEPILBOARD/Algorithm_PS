#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, ans;
bool v[27];

int main()
{
    FASTIO;
    cin >> n;
    while(n--){
        bool flag = true;
        string s;
        cin >> s;
        v[s[0]-'a'] = true;
        for(int i = 1; i<s.length(); i++){
            if(s[i] != s[i-1] && v[s[i]-'a']){
                flag = false;
                break;
            }
            v[s[i]-'a'] = true; 
        }
        if(flag) ans++;
        memset(v, false, sizeof(v));
    }
    cout << ans;
    return 0;
}