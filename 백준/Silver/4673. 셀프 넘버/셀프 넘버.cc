#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

bool notself[10001];

int main()
{
    FASTIO;

    for(int i = 1; i<=10000; i++){
        int dn = i;
        int t = i;
        while(t){
            dn += t%10;
            t /= 10;
        }
        if(dn<=10000)notself[dn] = true;
    }

    for(int i = 1; i<=10000; i++){
        if(notself[i]) continue;
        cout << i <<"\n";
    }
    return 0;
}