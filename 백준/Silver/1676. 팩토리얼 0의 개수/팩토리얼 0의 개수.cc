#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int cnt[501];

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cnt[i] = cnt[i-1];
        int x = i;
        while(x%10 == 0){
            cnt[i]++;
            x /= 10;
        }
        while(x%5 == 0){
            cnt[i]++;
            x /= 5;
        }
    }
    cout << cnt[n];
    return 0;
}