#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;
set<int> s;

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        int e; cin >> e;
        s.insert(e);
    }
    cin >> m;
    for(int i = 0; i<m; i++){
        int e; cin >> e;
        cout << s.count(e) <<"\n";
    }
    
    return 0;
}