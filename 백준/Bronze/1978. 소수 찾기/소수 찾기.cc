#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int a[100];

signed main()
{
    FASTIO;
    cin >> n;
    
    int ans = 0;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        if(a[i] == 1) continue;
        bool flag = true;
        for(int j = 2; j<=sqrt(a[i]); j++){
            if(a[i]%j == 0){
                flag = false;
                break;
            }
        }
        if(flag) ans++;
    }
    cout << ans;
    return 0;
}