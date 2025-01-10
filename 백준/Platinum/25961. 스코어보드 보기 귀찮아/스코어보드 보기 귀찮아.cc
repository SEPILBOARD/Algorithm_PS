#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, s, q;

pair<int,int> solcnt[500001]; // i번째 사람이 몇개 풀었는지
int solrank[500001]; // i개를 맨 마지막에 푼사람이 몇등인지지
int mx_solcnt;
int cur_rank;

int main()
{
    FASTIO;

    cin >> n >> s; cur_rank = n;
    cin >> q;
    while(q--){
        int e; cin>> e;
        solcnt[e].first++;
        solrank[solcnt[e].first]++;
        mx_solcnt = max(mx_solcnt, solcnt[e].first);

        if(e == 1){
            cur_rank = solrank[solcnt[1].first];
        }
        else{
            if(solcnt[e].first == solcnt[1].first+1 && solcnt[e].second < solcnt[1].second){
                cur_rank++;
            }
        }
        solcnt[e].second = q;
        int lo = 0; int hi = mx_solcnt+1;
        while(lo+1 < hi){
            int mid = (lo+hi)/2;
            if(solrank[mid] < s) hi = mid;
            else lo = mid;
        }
        if(solcnt[e].first == 0) cur_rank = n;
        if(cur_rank <= s) cout << cur_rank <<" 0\n";
        else cout << cur_rank << " " << hi - solcnt[1].first <<"\n";
    }
    
    return 0;
}