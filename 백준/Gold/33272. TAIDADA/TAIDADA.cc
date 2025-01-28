#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m, k;
bool v[1000000001];
int ans[200001];

int main()
{
    FASTIO;
    cin >> n >> m >> k;
    
    int cn= 1;
    int idx = n;
    while(idx--){
        while(cn <= m){
            if(!v[cn^k]) break;
            else cn++;
        }
        if(cn > m){
            cout << "-1";
            return 0;
        }

        ans[idx] = cn;
        v[cn] = true;
        v[cn^k] = true;
        cn++;
    }
    for(int i = 0; i<n; i++){
        cout << ans[i] <<" ";
    }
    return 0;
}