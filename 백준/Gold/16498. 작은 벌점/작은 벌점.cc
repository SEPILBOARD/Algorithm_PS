#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int an, bn, cn;
int A[1005], B[1005], C[1005];

signed main()
{
    FASTIO;
    cin >> an >> bn >> cn;
    for(int i = 0; i<an; i++) cin >> A[i];
    for(int i = 0; i<bn; i++) cin >> B[i];
    for(int i = 0; i<cn; i++) cin >> C[i];

    sort(A, A+an);
    sort(B, B+bn);
    sort(C, C+cn);

    int ans = 2e+9+1;
    for(int i = 0; i<an; i++){
        int a = A[i];

        int bidx = lower_bound(B, B+bn, a)-B;
        int cidx = lower_bound(C, C+cn, a)-C;

        vector<int> tb;
        vector<int> tc;

        if(bidx != bn) tb.push_back(B[bidx]);
        if(bidx != 0) tb.push_back(B[bidx-1]);
        if(cidx != cn) tc.push_back(C[cidx]);
        if(cidx != 0) tc.push_back(C[cidx-1]);

        for(int b: tb){
            for(int c: tc){
                // printf("%d %d %d\n", a, b, c);
                ans = min(ans, max(a, max(b, c))-min(a, min(b, c)));
            }
        }
    }

    cout << ans;
    return 0;
}