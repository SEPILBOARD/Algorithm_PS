#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int cmd;
char c;

deque<char> dq;
stack<int> st;

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> cmd;
        switch (cmd)
        {
        case 1:
            cin >> c;
            dq.push_back(c);
            st.push(1);
            break;
        case 2:
            cin >> c;
            dq.push_front(c);
            st.push(2);
            break;
        case 3:
            if(!dq.empty()){
                if(st.top() == 1) dq.pop_back();
                else dq.pop_front();

                st.pop();
            }
            break;
        default:
            break;
        }
    }

    if(dq.empty()) cout << "0";
    while(!dq.empty()){
        cout << dq.front();
        dq.pop_front();
    }
    return 0;
}