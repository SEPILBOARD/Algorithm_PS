#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
vector<int> v;

void solve()
{
    v.clear();
    v.push_back(-1);
    for(int i = 0; i<n; i++){
        int e; cin >> e;
        if(v.back()<e) v.push_back(e);
        else v[lower_bound(v.begin(), v.end(), e) - v.begin()] = e;
    }
    cout << v.size()-1 <<"\n";
}

int main()
{
    FASTIO;
    while(cin >> n) solve();    
    return 0;
}