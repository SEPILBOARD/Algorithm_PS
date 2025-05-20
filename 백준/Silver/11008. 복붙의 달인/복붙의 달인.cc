#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

void solve()
{
    string s, c;
    cin >> s >> c;
    vector<char> st;
    int cnt = 0;
    for(int i = 0; i<s.length(); i++){
        st.push_back(s[i]);
        if(st.size() >= c.length() && st.back() == c.back()){
            int idx = st.size()-1;
            bool flag = true;
            for(int j = c.size()-1; j>=0; j--){
                if(st[idx] != c[j]){
                    flag = false;
                    break;
                }
                idx--;
            }
            if(flag){
                cnt++;
                for(int j = 0; j<c.length(); j++)
                    st.pop_back();
            }
        }
    }
    cout << st.size() + cnt <<"\n";
    // for(char e: st) cout << e;
}

int main()
{
    FASTIO;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}