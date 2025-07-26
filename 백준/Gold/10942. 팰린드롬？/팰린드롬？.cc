#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;
int a[4040];
int sidx[4040];

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 2; i<=2*n; i+=2){
        cin >> a[i];
    }

    for(int i = 1; i<=2*n; i++){
        int l = i, r = i;
        while(l>=1 && r<=2*n && a[l] == a[r]){
            l--;
            r++;
        }
        sidx[i] = l+1;
    }

    cin >> m;
    for(int i = 0; i<m; i++){
        int s, e;
        cin >> s >> e;
        if(sidx[s+e]>2*s) cout << "0\n";
        else cout << "1\n";
    }

    // for(int i = 1; i<=2*n; i++){
    //     cout << a[i] <<" ";
    // }
    // cout << "\n";
    // for(int i = 1; i<=2*n; i++){
    //     cout << sidx[i] <<" ";
    // }

    return 0;
}