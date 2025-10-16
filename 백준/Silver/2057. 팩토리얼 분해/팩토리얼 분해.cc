#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

ll n;
ll facto[30];

signed main()
{
    FASTIO;
    cin >> n;

    facto[0] = 1;
    for(int i = 1; i<=19; i++){
        facto[i] = facto[i-1]*i;
    }

    for(int s = 1; s<1<<20; s++){
        ll t = 0;
        for(int i = 0; i<20; i++){
            if(s&(1<<i)) t+=facto[i];
        }
        if(t == n){
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}