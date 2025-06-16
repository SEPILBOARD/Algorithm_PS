#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

string s;

int main()
{
    FASTIO;
    getline(cin, s);
    while(s!="."){
        int n = s.length();
        bool flag = true;
        stack<char> st;
        for(int i = 0; i<n; i++){
            if(s[i] == '(') st.push('(');
            else if(s[i] == '[') st.push('[');

            else if(s[i] == ')'){
                if( st.empty() || st.top() != '('){
                    flag = false;
                    break;
                }
                st.pop();
            }
            else if(s[i] == ']'){
                if(st.empty() || st.top() != '['){
                    flag = false;
                    break;
                }
                st.pop();
            }
        }
        if(flag && st.empty()) cout << "yes\n";
        else cout << "no\n";
        getline(cin, s);
    }
    return 0;
}