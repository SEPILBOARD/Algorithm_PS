#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;
set<string> s;

int main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        string e; cin >> e;
        s.insert(e);
    }
    vector<string> ans;
    for(int i = 0; i<m; i++){
        string e; cin >> e;
        if(s.count(e)) ans.push_back(e);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() <<"\n";
    for(string e: ans) cout << e << "\n";
    return 0;
}