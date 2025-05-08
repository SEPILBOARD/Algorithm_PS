#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int a[100'001];

int main()
{
    FASTIO;
    cin >> n;
    int ans = 0;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
        if(a[i] == i) ans ++;
    }

    cout << ans <<"\n";
    for(int i = 1; i<=n; i++){
        if(a[i] == i){
            if(i!=1) cout <<"1 ";
            else cout << "2 ";
        }
        else cout << a[i] <<" ";
    }
    
    return 0;
}