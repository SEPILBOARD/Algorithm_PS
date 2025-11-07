#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int n;
pair<int, int> a[1010];
int iq[1010];
vector<int> adj[1010];

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> iq[i];
    }

    for(int i = 0; i<n-1; i++){
        int m, e;
        cin >> m >> e;
        adj[m].push_back(e);
    }

    for(int i = 1; i<=n; i++){
        vector<pair<int, int>> v;
        if(adj[i].size()>0){
            for(int e: adj[i]){
                v.push_back({iq[e],e});
            }
            sort(v.begin(), v.end(), greater<>());

            cout << i <<" " << v[0].second <<"\n";
            for(int i = 1; i<v.size(); i++){
                cout << v[i-1].second << " " << v[i].second <<"\n";
            }
        }
    }
    
    return 0;
}