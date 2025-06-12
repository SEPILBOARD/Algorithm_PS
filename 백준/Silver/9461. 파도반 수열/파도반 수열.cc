#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

int n, t;
int p[101];

signed main()
{
    FASTIO;
    p[1] = p[2] = p[3] = 1;
    p[4] = p[5] = 2;
    for(int i = 6; i<=100; i++){
        p[i] = p[i-1] + p[i-5];
    }
    
    cin >> t;
    while(t--){
        cin >> n;
        cout << p[n] <<"\n";
    }
    return 0;
}