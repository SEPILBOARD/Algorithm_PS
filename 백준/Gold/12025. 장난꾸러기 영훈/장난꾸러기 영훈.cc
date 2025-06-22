#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

string s;
int k;
int cnt;
vector<char> ans;

int pt[62];

signed main()
{
    pt[0] = 1;
    for(int i = 1; i<61; i++){
        pt[i] = pt[i-1]*2;
    }

    FASTIO;
    cin >> s;
    cin >> k;

    for(int i = 0; i<s.length(); i++){
        if(s[i] == '1' || s[i] == '2' || s[i] == '6' || s[i] == '7'){
            cnt++;
        }
    }

    if(k>pt[cnt]){
        cout << -1;
        return 0;
    }

    for(int i = 0; i<s.length(); i++){
        if(s[i] != '1' && s[i] != '2' && s[i] != '6' && s[i] != '7'){
            ans.push_back(s[i]);
            continue;
        }

        if(k>pt[cnt-1]){
            if(s[i] == '1' || s[i] == '2') ans.push_back(char(s[i]+5));
            else ans.push_back(s[i]);
            k -= pt[cnt-1];
        }
        else{
            if(s[i] == '6' || s[i] == '7') ans.push_back(char(s[i]-5));
            else ans.push_back(s[i]);
        }
        cnt--;
    }
    for(char c: ans) cout << c;
    return 0;
}