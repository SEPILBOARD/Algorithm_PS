#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;
bool brk[10];

int main()
{
    FASTIO;
    cin >> n >> m;
    int ans = 987654321;
    while(m--){
        int e; cin >>e;
        brk[e] = true;
    }

    if(!brk[0]) ans = n+1;
    ans = min(ans, abs(n-100));

    for(int i = 1; i<=999999; i++){
        int t = i;
        int cnt = 0;
        bool flag = false;
        while(t){
            cnt++;
            if(brk[t%10]){
                flag = true;
                break;
            }
            t /= 10;
        }
        if(flag) continue;
        // if(ans>abs(n-i)) cout << i <<": "<<abs(n-i)<<"\n";
        ans = min(ans, abs(n-i)+cnt);
    }
    cout << ans;
    return 0;
}