#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

int n;
vector<int> idxs[65];

signed main()
{
    FASTIO;
    cin >> n;
    int fidx = 0;
    for(int i = 0; i<n; i++){
        int e; cin >> e;
        idxs[e].push_back(fidx);
        fidx += 1LL<<(e-1);
    }

    int ans = 0;
    for(int i = 1; i<=60; i++){
        if(!idxs[i].empty()) ans = i;
        sort(idxs[i].begin(), idxs[i].end());
        for(int idx: idxs[i]){
            int nidx = idx + (1LL<<(i-1));
            auto lb = lower_bound(idxs[i].begin(), idxs[i].end(), nidx);
            if(lb!=idxs[i].end() && *lb == nidx){
                idxs[i+1].push_back(idx);
            }
        }
    }
    cout << ans <<"\n";
    return 0;
}