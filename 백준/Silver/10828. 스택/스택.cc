#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
stack<int> st;

int main()
{
    FASTIO;
    cin >> n;
    while(n--){
        string cmd;
        cin >> cmd;
        if(cmd == "push"){
            int in; cin >> in;
            st.push(in);
        }
        else if(cmd == "pop"){
            if(st.empty()) cout << "-1\n";
            else{
                cout << st.top()<<"\n";
                st.pop();
            }
        }
        else if(cmd == "size"){
            cout << st.size() <<"\n";
        }
        else if(cmd == "empty"){
            int out = st.empty();
            cout << out <<"\n";
        }
        else{
            if(st.empty()) cout << "-1\n";
            else cout << st.top() <<"\n";
        }
    }
    return 0;
}