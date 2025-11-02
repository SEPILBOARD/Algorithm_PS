#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int n, m;
unordered_map<string, int> idx;
string s[100'001];

signed main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> s[i];
        idx[s[i]] = i;
    }

    for(int i = 0; i<m; i++){
        string input;
        cin >> input;
        if('1'<= input[0] && input[0]<='9'){
            cout << s[stoi(input)] <<"\n";
        }
        else{
            cout << idx[input] <<"\n";
        }
    }

    return 0;
}