#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m, k;
int a[100'001];
int sp[100'001][32];

int main()
{
    FASTIO;
    cin >> n >> k >> m;
    if(m == 1){
        for(int i = 0; i<n; i++){
            cin >> a[i];
            cout << a[i] <<" ";
        }   
        return 0;
    }

    for(int i = 0; i<n; i++) cin >> a[i];
    for(int i = 1; i<=k; i++) cin >> sp[i][0];

    for(int i = 1; i<=30; i++){
        for(int j = 1; j<=k; j++){
            sp[j][i] = sp[sp[j][i-1]][i-1];
        }
    }

    for(int i = 0; i<n; i++){
        int jp = m-1;
        int bf = a[i];
        for(int j = 30; j>=0; j--){
            if(jp-(1<<j) < 0) continue;
            bf = sp[bf][j];
            jp -= (1<<j);
        }
        cout << bf <<" ";
    }
    return 0;
}