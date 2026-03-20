#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, m;
priority_queue<int, vector<int>, greater<>> curT;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> spq;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> rpq;

signed main()
{
    FASTIO;
    cout.precision(7);
    cout << fixed;

    cin >> n >> m;
    
    for(int i = 0; i<n; i++){
        int t, k;
        char c;
        cin >> t >> c >> k;

        if(c == 'S'){
            spq.push({t, k});
        }
        else{
            rpq.push({t, k});
        }
    }

    for(int i = 0; i<m; i++)
        curT.push(0);

    ll st = 0ll;
    int scnt = 0;

    ll rt = 0ll;
    int rcnt = 0;

    while(!spq.empty() || !rpq.empty()){
        int cur = curT.top();
        curT.pop();

        if(rpq.empty()){
            auto[t, k] = spq.top();
            spq.pop();

            cur = max(cur, t)+k;

            st += cur-t;
            scnt++;

            curT.push(cur);
        }

        else if(spq.empty()){
            auto[t, k] = rpq.top();
            rpq.pop();

            cur = max(cur, t)+k;

            rt += cur-t;
            rcnt++;

            curT.push(cur);
        }

        else if(cur<= spq.top().first && cur<= rpq.top().first){
            if(rpq.top().first < spq.top().first){
                auto[t, k] = rpq.top();
                rpq.pop();

                cur = max(cur, t)+k;

                rt += cur-t;
                rcnt++;

                curT.push(cur);
            }
            else{
                auto[t, k] = spq.top();
                spq.pop();

                cur = max(cur, t)+k;

                st += cur-t;
                scnt++;

                curT.push(cur);
            }
        }

        else if(spq.top().first <= cur){
            auto[t, k] = spq.top();
            spq.pop();

            cur = max(cur, t)+k;

            st += cur-t;
            scnt++;

            curT.push(cur);
        }

        else{
            auto[t, k] = rpq.top();
            rpq.pop();

            cur = max(cur, t)+k;

            rt += cur-t;
            rcnt++;

            curT.push(cur);
        }
    }

    if(scnt == 0) cout << "0 ";
    else cout << st/double(scnt) <<" ";

    if(rcnt == 0) cout << "0 ";
    else cout << rt/double(rcnt) <<"\n";

    return 0;
}