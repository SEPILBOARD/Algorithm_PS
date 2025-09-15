#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define E 15
#define S 28
#define M 19

int e, s, m;
int ce = 1, cs = 1, cm = 1;

signed main()
{
    FASTIO;
    cin >> e >> s >> m;
    
    for(int i = 1; i<=E*S*M+1; i++){
        if(ce == e && cs == s && cm == m){
            cout << i;
            return 0;
        }
        
        ce++;
        cs++;
        cm++;
        if(ce > E) ce = 1;
        if(cs > S) cs = 1;
        if(cm > M) cm = 1;
    }

    return 0;
}