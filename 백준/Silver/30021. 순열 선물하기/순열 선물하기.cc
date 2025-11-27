#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;

signed main()
{
    FASTIO;
    cin >> n;   

    if(n == 1){
        cout << "YES\n";
        cout << "1\n";
    }
    else if(n == 2){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        cout << "1 3 2 ";
        for(int i = 4; i<=n; i++) cout << i <<" ";
    }
    return 0;
}   