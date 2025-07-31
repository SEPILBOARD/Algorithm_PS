#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int g[100'001];

bool v[100'001];
bool t[100'001];

void solve()
{
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> g[i];

    memset(v, false, sizeof(v));
    memset(t, false, sizeof(t));

    for(int i = 1; i<=n; i++){
        if(v[i]) continue;
        
        stack<int> st;
        st.push(i);
        while(!v[g[st.top()]]){
            v[g[st.top()]] = true;
            st.push(g[st.top()]);
        }

        int p = g[st.top()];
        vector<int> temp;
        while(!st.empty() && st.top() != p){
            temp.push_back(st.top());
            st.pop();
        }

        if(!st.empty()){
            for(int e: temp) t[e] = true;
            t[p] = true;
        }
    }
    
    int ans = 0;
    for(int i = 1; i<=n; i++){
        if(!t[i]){
            ans++;
        }
    }
    cout << ans <<"\n";
}

signed main()
{
    FASTIO;
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}