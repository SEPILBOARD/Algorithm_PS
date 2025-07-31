#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

string t, p;

vector<int> makeTable(string pattern)
{   
    int psize = pattern.size();
    vector<int> table(psize, 0);

    for(int i = 1, j = 0; i<psize; i++){
        while(j>0 && pattern[i] != pattern[j]){
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }

    return table;
}

vector<int> KMP(string all, string pattern)
{
    vector<int> ans;
    int asize = all.size();
    int psize = pattern.size();
    vector<int> table = makeTable(pattern);

    for(int i = 0, j = 0; i<asize; i++){
        while(j>0 && all[i] != pattern[j]){
            j = table[j-1];
        }
        if(all[i] == pattern[j]){
            if(j == psize-1){
                ans.push_back(i-psize+2);
                j = table[j];
            }
            else j++;
        }
    }

    return ans;
}

signed main()
{
    FASTIO;
    getline(cin, t);
    getline(cin, p);
    
    vector<int> ans = KMP(t, p);

    cout << ans.size() <<"\n";
    for(int e: ans) cout << e <<" ";
    return 0;
}