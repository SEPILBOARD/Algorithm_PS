#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int a[1'000'001];
int table[1'000'001];

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = n-1; i>=0; i--) cin >> a[i];

    
    for(int i = 1, j = 0; i<n; i++){
        while(j>0 && a[i] != a[j]) j = table[j-1];
        if(a[i] == a[j]) table[i] = ++j;
    }

    int mx = 0;
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(table[i] > mx){
            mx = table[i];
            cnt = 1;
        }
        else if(table[i] == mx) cnt++;
    }

    if(mx == 0) cout << -1;
    else{
        cout << mx << " " <<cnt;
    }
    return 0;
}