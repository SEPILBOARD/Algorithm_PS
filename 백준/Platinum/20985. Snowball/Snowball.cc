#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

int mr, ml, cur;
int n, q;
int x[200'001];
pair<int, int> L[200'001];
int ans[200'001];
bool lcheck[200'001];
bool rcheck[200'001];

signed main()
{
    FASTIO;
    cin >> n >> q;
    cin >> x[0];
    for(int i = 1; i<n; i++){
        cin >> x[i];
        L[i-1] = {x[i]-x[i-1], i-1};
    }

    sort(L, L+n-1);
    int idx = 0;
    int ridx = 0;

    while(q--){
        int w;
        cin >> w;
        
        cur += w;
        // if(cur > 0){
        //     int tmr = max(mr, tmr);
        //     while(lidx)

        //     mr = max(tmr, mr);
        // }
        int tml = min(ml, cur);
        int tmr = max(mr, cur);

        while(idx<n-1 && L[idx].first <= tmr-tml){
            auto [len, i] = L[idx];

            if(w<0){
                ans[i] += mr;
                rcheck[i] = true;

                ans[i+1] += len-mr;
                lcheck[i+1] = true;
            }
            else{
                ans[i] += len+ml;
                rcheck[i] = true;

                ans[i+1] -= ml;
                lcheck[i+1] = true;
            }
            idx++;
        }
        ml = tml;
        mr = tmr;

        // cout << ml <<" " <<mr <<"\n";
        // for(int i = 0; i<n; i++) cout << ans[i] <<" ";
        // cout << "\n";
    }

    for(int i = 0; i<n; i++){
        if(!rcheck[i]) ans[i] += mr;
        if(!lcheck[i]) ans[i] -= ml;
        cout << ans[i] <<"\n";
    }
    
    return 0;
}