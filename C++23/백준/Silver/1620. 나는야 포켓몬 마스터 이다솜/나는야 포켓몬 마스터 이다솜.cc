#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, m;
vector<string> iton;
map<string, int> ntoi;

signed main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        
        iton.push_back(s);
        ntoi[s] = i;
    }

    for(int i = 0; i<m; i++){
        string s;
        cin >> s;
        if('0'<= s[0] && s[0]<='9'){
            int idx = stoi(s);
            cout << iton[idx-1] <<"\n";
        }
        else{
            cout << ntoi[s]+1 <<"\n";
        }
    }

    return 0;
}