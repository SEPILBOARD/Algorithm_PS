#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, s;
int a[20];

int main()
{
    FASTIO;
    cin >> n >> s;
    for(int i = 0; i<n; i++) cin >> a[i];

    int ans = 0;
    for(int i = 1; i<(1<<n); i++){
        int sum = 0;
        for(int j = 0; j<n; j++){
            if(i&(1<<j)) sum += a[j];
        }
        if(sum == s) ans++;
    }
    cout << ans;
    return 0;
}