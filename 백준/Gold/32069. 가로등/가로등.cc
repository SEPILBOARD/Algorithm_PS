#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int
#define MAX_K 500000

int l, n, k;
set<int> s;
queue<pair<int, int>> q;

signed main()
{
    FASTIO;
    cin >> l >> n >> k;
    for(int i = 0; i<n; i++){
        int e; cin >> e;
        q.push({e, 0});
        s.insert(e);
    }
    //BFS
    while(k--){
        int dist = q.front().second;
        cout << dist <<"\n";
        int x = q.front().first;
        q.pop();
        if(!s.count(x-1) && x-1>=0){
            q.push({x-1, dist+1});
            s.insert(x-1);
        }
        if(!s.count(x+1) && x+1<=l){
            q.push({x+1, dist+1});
            s.insert(x+1);
        }
    }
    return 0;
}