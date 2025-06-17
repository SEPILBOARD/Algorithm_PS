#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int num[12];
int op[4];
int mx = -1e+9-1;
int mn = 1e+9+1;

void bt(int a, int s, int p, int d, int idx, int cur)
{
    if(idx == n){
        mx = max(mx, cur);
        mn = min(mn, cur);
        return;
    }
    
    if(a>0) bt(a-1, s, p, d, idx+1, cur+num[idx]);
    if(s>0) bt(a, s-1, p, d, idx+1, cur-num[idx]);
    if(p>0) bt(a, s, p-1, d, idx+1, cur*num[idx]);
    if(d>0) bt(a, s, p, d-1, idx+1, cur/num[idx]);
}

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++) cin >> num[i];
    for(int i = 0; i<4; i++) cin >> op[i];
    
    bt(op[0], op[1], op[2], op[3], 1, num[0]);
    cout << mx <<"\n" << mn;
    return 0;
}