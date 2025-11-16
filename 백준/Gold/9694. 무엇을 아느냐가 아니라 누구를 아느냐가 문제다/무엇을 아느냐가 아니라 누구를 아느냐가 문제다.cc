#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;
#define INF 2139062143

int n, m;
int dist[22];
vector<pair<int, int>> adj[22];
int trk[22];

void solve()
{
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({z, y});
        adj[y].push_back({z, x});
    }

    memset(dist, 0x7f, sizeof(dist));
    dist[0] = 0;
    trk[0] = -1;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.push({0, 0, -1});
    while(!pq.empty()){
        auto[d, cur, prev] = pq.top();
        pq.pop();

        if(dist[cur] != d) continue;
        trk[cur] = prev;
        for(auto[nw, next]: adj[cur]){
            if(d+nw >= dist[next]) continue;
            dist[next] = d+nw;
            pq.push({dist[next], next, cur});
        }
    }

    if(dist[m-1] == INF) cout << "-1\n";
    else{
        stack<int> st;
        st.push(m-1);
        while(trk[st.top()] != -1){
            st.push(trk[st.top()]);
        }
        while(!st.empty()){
            cout << st.top() <<" ";
            st.pop();
        }
        cout << "\n";
    }


    for(int i = 0; i<m; i++){
        trk[i] = 0;
        adj[i].clear();
    }
}

signed main()
{
    FASTIO;
    int _tc; cin >> _tc;
    for(int i = 1; i<=_tc; i++){
        cout << "Case #" <<i <<": ";
        solve();
    }
    return 0;
}