#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, k, ans;
bool v[220'002];

int main()
{
    FASTIO;
    cin >> n >> k;

    queue<pair<int, int>> q;
    q.push({n,0});
    v[n] = true;
    while(!q.empty()){
        auto [cur, d] = q.front();
        q.pop();

        if(cur<100'000 && !v[cur+1]){
            if(cur+1 == k){
                ans = d+1;
                break;
            }
            v[cur+1] = true;
            q.push({cur+1, d+1});
        }
        if(cur>0 && !v[cur-1]){
            if(cur-1 == k){
                ans = d+1;
                break;
            }
            v[cur-1] = true;
            q.push({cur-1, d+1});
        }
        if(cur<110'000 && !v[2*cur]){
            if(2*cur == k){
                ans = d+1;
                break;
            }
            v[2*cur] = true;
            q.push({2*cur, d+1});
        }
    }
    cout << ans;
    return 0;
}