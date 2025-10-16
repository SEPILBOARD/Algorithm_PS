#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;
#define MOD 1'000'000'000

int n;
ll fibo[1'000'001];

signed main()
{
    FASTIO;
    cin >> n;

    fibo[0] = 0;
    fibo[1] = 1;

    for(int i = 2; i<=abs(n); i++){
        fibo[i] = (fibo[i-1] + fibo[i-2])%MOD;
        
    }

    if(n<0 && n%2 == 0) cout << "-1\n";
    else cout << (n!=0) <<"\n";
    
    cout << fibo[abs(n)];

    return 0;
}