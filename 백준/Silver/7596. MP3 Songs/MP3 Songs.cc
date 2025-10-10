#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;
string s[300];

void solve()
{
    getline(cin, s[0]);
    for(int i = 0; i<n; i++){
        getline(cin, s[i]);
    }
    sort(s, s+n);
    for(int i = 0; i<n; i++){
        cout << s[i] <<"\n";
    }
}

signed main()
{
    FASTIO;
    cin >> n;
    int num = 1;
    while(n != 0){
        cout << num++ <<"\n";
        solve();
        cin >> n;
    }
    return 0;
}