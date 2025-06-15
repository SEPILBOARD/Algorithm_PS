#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define INF 2000000001

int n;
vector<int> ev;
vector<int> od;

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        int e; cin >> e;
        if(e&1) od.push_back(e);
        else ev.push_back(e);
    }
    sort(od.begin(), od.end());
    sort(ev.begin(), ev.end());
    
    int ocnt = od.size();
    int ecnt = ev.size();
    int ans = INF;
    for(int i = 1; i<max(ocnt, ecnt); i++){
        if(i<ocnt) ans = min(ans, od[i]-od[i-1]);
        if(i<ecnt) ans = min(ans, ev[i]-ev[i-1]);
    }
    if(ans == INF) cout << "-1 ";
    else cout << ans <<" ";
    
    ans = INF;
    for(int i = 0; i<ocnt; i++){
        int idx = lower_bound(ev.begin(), ev.end(), od[i]) - ev.begin();
        if(idx<ecnt) ans = min(ans, ev[idx]-od[i]);
        if(idx>0) ans = min(ans, od[i] - ev[idx-1]);
    }
    if(ans == INF) cout << "-1 ";
    else cout << ans <<" ";

    return 0;
}