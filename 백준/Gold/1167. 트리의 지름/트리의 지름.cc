#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;
vector<pair<int, int>> adj[100'001];
bool v1[100'001];
bool v2[100'001];

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        int cur;
        cin >> cur;

        int x;
        cin >> x;
        while(x != -1){
            int d;
            cin >> d;
            adj[cur].push_back({x, d});
            cin >> x;
        }
    }

    int last = 1;
    int ld = 0;
    queue<pair<int, int>> q1;
    q1.push({1, 0});
    v1[1] = true;
    while(!q1.empty()){
        auto[cur, d] = q1.front();
        q1.pop();
        if(ld<d){
            ld = d;
            last = cur;
        }

        for(auto [e, w]: adj[cur]){
            if(v1[e]) continue;
            v1[e] = true;
            q1.push({e, d+w});
        }
    }

    int ans = 0;
    queue<pair<int, int>> q2;
    q2.push({last, 0});
    v2[last] = true;
    while(!q2.empty()){
        auto[cur, d] = q2.front();
        q2.pop();
        ans = max(ans, d);

        for(auto [e, w]: adj[cur]){
            if(v2[e]) continue;
            v2[e] = true;
            q2.push({e, d+w});
        }
    }
    
    cout << ans;
    return 0;
}   