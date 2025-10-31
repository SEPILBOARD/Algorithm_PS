#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, m;
int a[100][10'001];
vector<int> itov[100];

int vtoi(int i, int x)
{
    return lower_bound(itov[i].begin(), itov[i].end(), x)-itov[i].begin();
}

signed main()
{
    FASTIO;
    cin >> m >> n;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin >> a[i][j];
            itov[i].push_back(a[i][j]);
        }

        sort(itov[i].begin(), itov[i].end());
        itov[i].erase(unique(itov[i].begin(), itov[i].end()), itov[i].end());   
    }

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            a[i][j] = lower_bound(itov[i].begin(), itov[i].end(), a[i][j])-itov[i].begin();
        }
    }

    int ans = 0;
    for(int i = 0; i<m; i++){
        for(int j = i+1; j<m; j++){
            bool flag = true;
            for(int k = 0; k<n; k++){
                if(a[i][k] != a[j][k]){
                    flag = false;
                    break;
                }
            }

            if(flag) ans++;
        }
    }
    cout << ans;
    return 0;
}