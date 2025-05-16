#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;

int main()
{
    FASTIO;
    cin >> n;
    vector<pair<int, string>> v;
    for(int i = 0; i<n; i++){
        string name, jae, win;
        int shake, apc;
        cin >> name >> jae >> win >> shake >> apc;
        if(jae == "hewhak" || win == "winner") continue;
        if(shake>=1 && shake<=3) continue;
        v.push_back({apc, name});
    }

    sort(v.begin(), v.end());
    vector<string> ans;
    for(auto e: v){
        ans.push_back(e.second);
        if(ans.size()>=10) break;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() <<"\n";
    for(string e: ans) cout << e <<"\n";

    return 0;
}