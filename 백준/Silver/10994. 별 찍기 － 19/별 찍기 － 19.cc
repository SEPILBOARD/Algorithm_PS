#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int N;
char ans[502][502];

signed main()
{
    FASTIO;
    cin >> N;

    int n = (N-1)*4 + 1;
    
    for(int i = 0; i<n; i+=2){
        for(int j = i; j<n-i; j++){
            ans[i][j] = '*';
            ans[j][i] = '*';
            ans[n-1-i][j] = '*';
            ans[j][n-1-i] = '*';
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(ans[i][j] == NULL) cout << ' ';
            else cout << '*';
        }
        cout << '\n';
    }

    return 0;
}