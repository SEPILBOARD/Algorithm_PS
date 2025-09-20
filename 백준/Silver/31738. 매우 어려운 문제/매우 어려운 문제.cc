#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

long long int n;
int m;

int main()
{
    FASTIO;
    cin >> n >> m;

    if(n>=m) cout << 0;
    else{
        long long int ans = 1;
        for(int i = 2; i<=n; i++){
            ans = (ans*i)%m;
        }
        cout << ans;
    }
    return 0;
}