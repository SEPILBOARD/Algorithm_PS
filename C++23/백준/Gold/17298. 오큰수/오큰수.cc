#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;
vector<pair<int, int>> stk;

signed main()
{
    FASTIO;

    cin >> n;
    vector<int> ans(n, -1);
    for(int i = 0; i<n; i++){
        int a; cin >> a;
        while(!stk.empty() && stk.back().first<a){
            auto[v, idx] = stk.back();
            stk.pop_back();
            
            ans[idx] = a;
        }
        stk.push_back({a, i});
    }

    for(int e: ans) cout << e <<" ";
    
    return 0;
}