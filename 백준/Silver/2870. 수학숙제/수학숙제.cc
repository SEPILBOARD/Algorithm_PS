#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int n;
string s;
vector<string> ans;

bool compare(const string &fs, const string &sc)
{   
    if(fs.size() == sc.size()) return fs<sc;
    return fs.size() < sc.size();
}

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> s;
        string cur = "";
        for(char e: s){
            if('0'<= e && e<='9'){
                cur.push_back(e);
            }
            else{
                if(cur.size() != 0){
                    ans.push_back(cur);
                    cur = "";
                }
            }
        }
        if(cur.size() != 0) ans.push_back(cur);
    }

    for(int i = 0; i<ans.size(); i++){
        int idx = 0;
        while(idx != ans[i].size() && ans[i][idx] == '0') idx++;
        ans[i].erase(0, idx);
        if(ans[i].size() == 0) ans[i] = "0";
    }

    sort(ans.begin(), ans.end(), compare);
    for(string e: ans){
        cout << e << "\n";
    }

    return 0;
}