#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
stack<int> st;
signed main()
{
    FASTIO;
    cin >> n;
    if(!n) cout << 0;
    while(n){
        int q = n/-2;
        int r = n%-2;
        if(r == -1){
            q++;
            r = 1;
        }
        st.push(r);
        n = q;
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    return 0;
}