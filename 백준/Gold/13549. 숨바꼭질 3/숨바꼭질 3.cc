#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;
#define INF 2139062143

int n, k;
int dist[220'001];



signed main()
{
    FASTIO;
    memset(dist, 0x7f, sizeof dist);

    cin >> n >> k;
    
    dist[n] = 0;
    deque<pair<int, int>> dq;
    dq.push_back({n, 0});
    
    while(!dq.empty()){
        auto [cur, d] = dq.front();
        dq.pop_front();

        if(d != dist[cur]) continue;
        if(cur>0 && dist[cur-1]>d+1){
            dq.push_back({cur-1, d+1});
            dist[cur-1] = d+1;
        }
        if(cur<=100'000 && dist[cur+1]>d+1){
            dq.push_back({cur+1, d+1});
            dist[cur+1] = d+1;
        }
        if(cur<=100'000 && dist[2*cur]>d){
            dq.push_front({2*cur, d});
            dist[2*cur] = d;
        }
    }
    cout << dist[k];

    return 0;
}