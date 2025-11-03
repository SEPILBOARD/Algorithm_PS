#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

vector<int> adj[13];
int idg[13];

signed main()
{
    FASTIO;
    for(int i = 0; i<12; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        idg[a]++;
        idg[b]++;
    }

    vector<int> s;
    for(int i = 1; i<=12; i++){
        if(idg[i]!= 1) continue;
        if(idg[adj[i][0]]!=3) continue;

        s.push_back(adj[i][0]);
    }
    
    for(int spica: s){
        for(int e: adj[spica]){
            if(idg[e] == 2){
                cout << spica;
                return 0;
            }
        }
    }
    
    return 0;
}