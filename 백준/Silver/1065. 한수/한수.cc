#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;

int main()
{
    FASTIO;
    cin >> n;

    if(n<100){
        cout << n;
        return 0;
    }
    else if(n == 1000){
        cout << 144;
        return 0;
    }

    int num[3];
    int ans = 99;
    for(int i = 111; i<=n; i++){
        int t = i;
        for(int i = 0; i<3; i++){
            num[i] = t%10; t/=10;    
        }
        if(num[0]-num[1] == num[1]-num[2]) ans++;
    }
    cout << ans;
    return 0;
}