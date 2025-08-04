#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, k, m;
vector<int> s[100];
vector<vector<int>> p; 

vector<int> makeTable(vector<int> pattern)
{
    vector<int> table(k, 0);
    for(int i = 1, j = 0; i<k; i++){
        while(j>0 && pattern[i] != pattern[j]) j = table[j-1];
        if(pattern[i] == pattern[j]) table[i] = ++j;
    }
    return table;
}

bool KMP(vector<int> all, vector<int> pattern)
{
    int asize = all.size();
    vector<int> table = makeTable(pattern);
    for(int i = 0, j = 0; i<asize; i++){
        while(j>0 && all[i] != pattern[j]) j = table[j-1];
        if(all[i] == pattern[j]){
            if(j == k-1) return true;
            else j++;
        }
    }
    return false;
}

signed main()
{
    FASTIO;
    cin >> n >> k;
    for(int i = 0; i<n; i++){
        int m; cin >> m;
        for(int j = 0; j<m; j++){
            int e; cin >> e;
            s[i].push_back(e);
        }
    }

    for(int j = 0; j<=s[0].size()-k; j++){
        vector<int> nwp(k);
        for(int r = j; r<j+k; r++){
            nwp[r-j] = s[0][r];
        }
        p.push_back(nwp);
    }
    
    for(int i = 0; i<p.size(); i++){
        bool flag = true;
        for(int j = 0; j<n; j++){
            if(KMP(s[j], p[i])) continue;
            vector<int> rp = p[i];
            reverse(rp.begin(), rp.end());
            if(KMP(s[j], rp)) continue;

            flag = false;
            break;
        }

        if(flag){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";

    // for(auto v: p){
    //     for(int e: v) cout << e << " ";
    //     cout << "\n";
    // }
    return 0;
}