#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int n, m;

int l[111];
int s[111];

vector<int> adj[110];
bool v[111];

signed main()
{
    FASTIO;

    cin >> n >> m;
    for(int i = 0; i<n; i++){
        int x, y;
        cin >> x >> y;
        l[x] = y;
    }
    for(int i = 0; i<m; i++){
        int x, y;
        cin >> x >> y;
        s[x] = y;
    }

    for(int i = 1; i<=100; i++){
        for(int j = 1; j<=6; j++){
            adj[i].push_back(i+j);
        }
    }

    queue<pair<int, int>> q;
    q.push({1, 0});


    while(!q.empty()){
        auto[x, d] = q.front();
        q.pop();
        
        if(x == 100){
            cout << d;
            return 0;
        }

        for(int e: adj[x]){
            while(l[e]) e = l[e];
            while(s[e]) e = s[e];
            if(v[e]) continue;

            v[e] = true;
            q.push({e, d+1});
        }
    }
    
    return 0;
}