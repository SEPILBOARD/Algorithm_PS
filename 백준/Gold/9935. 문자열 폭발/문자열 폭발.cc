#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

string s, b;
vector<char> st;

int main()
{
    FASTIO;
    cin >> s >> b;
    int blen = b.size();
    char lastb = b[blen-1];
    
    for(char e: s){
        st.push_back(e);
        int stlen = st.size();
        if(e == lastb && stlen>=blen){
            bool flag = true;
            int ivt = 2;
            while(ivt<=blen){
                if(st[stlen-ivt] != b[blen-ivt]){
                    flag = false;
                    break;
                }
                ivt++;
            }
            if(flag){
                int frq = blen;
                while(frq--) st.pop_back();
            }
        }
    }
    
    if(st.size()) for(char e: st) cout << e;
    else cout << "FRULA";

    return 0;
}