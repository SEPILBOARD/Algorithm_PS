#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int n;
int l, p;
pair<int, int> ab[10'005];
priority_queue<int> pq;

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> ab[i].first >> ab[i].second;
    }
    cin >> l >> p;

    sort(ab, ab+n);
    ab[n] = {l, 0};

    int cur = p;
    int cnt = 0;
    for(int i = 0; i<n+1; i++){
        if(cur < ab[i].first){
            while(!pq.empty() && cur<ab[i].first){
                cur += pq.top();
                pq.pop();
                cnt++;
            }
            if(cur<ab[i].first){
                cout << "-1";
                return 0;
            }
        }
        pq.push(ab[i].second);

        if(cur>= l){
            cout << cnt;
            return 0;
        }
    }
    
    return 0;
}