#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

int n, m;
int ans;
priority_queue<int> pq;
vector<pair<int,int>> tq;

signed main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        int e; cin >> e;
        pq.push(e);
    }
    for(int i = 0; i<m; i++){
        int t, q; cin >> t >> q;
        tq.push_back({t,q});
    }
    sort(tq.begin(), tq.end());

    for(int i = 0; i<m; i++){
        while(ans < tq[i].second){
            if(pq.empty()){
                cout << "-1";
                return 0;
            }
            ans += pq.top() + tq[i].first;
            pq.pop();
        }
    }
    while(!pq.empty()){
        ans += pq.top() + tq[m-1].first;
        pq.pop();
    }
    cout << ans;
    return 0;
}