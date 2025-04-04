#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

int n;
int cnt[1<<10];

signed main()
{
    FASTIO;
    cin >> n;
    while(n--){
        int x; cin >>x;
        int idx = 0;
        while(x){
            idx |= 1<<(x%10);
            x/=10;
        }
        cnt[idx]++;
    }
    int ans =0;
    for(int i = 0; i<(1<<10); i++){
        ans += cnt[i]*(cnt[i]-1)/2;
        for(int j = i+1; j<(1<<10); j++){
            if(!(i&j)) continue;
            ans += cnt[i]*cnt[j];
        }
    }
    cout << ans;
    return 0;
}