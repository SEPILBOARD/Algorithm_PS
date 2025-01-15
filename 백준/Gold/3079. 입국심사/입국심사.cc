#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define lli long long int
int n, m;
lli t[100000];
lli maxt = 0;

int main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        cin >> t[i];
        maxt = max(maxt, t[i]);
    }
    
    lli lo = 0; lli hi = (m/n+1)*maxt;
    while(lo+1 < hi){
        lli mid = (lo+hi)/2;
        lli passHum = 0;
        for(int i = 0; i<n; i++){
            passHum += mid/t[i];
        }
        if(passHum < m) lo = mid;
        else hi = mid;
    }
    cout << hi;
    return 0;
}