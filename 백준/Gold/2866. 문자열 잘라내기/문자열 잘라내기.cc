#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int r, c;
char a[1005][1005];

signed main()
{
    FASTIO;
    cin >> r >> c;
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            cin >> a[i][j];
        }
    }

    int lo = 0, hi = r;
    int cnt = 0;
    while(lo+1<hi){
        int mid = lo+hi>>1;
        
        set<string> s;
        for(int i = 0; i<c; i++){
            string t = "";
            for(int j = mid; j<r; j++){
                t.push_back(a[j][i]);
            }
            s.insert(t);
        }
        // cout << mid <<": " <<s.size() <<"\n";

        if(s.size() != c) hi = mid;
        else lo = mid;
    }
    cout << lo;

    return 0;
}