#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int a[4001];
int b[4001];
int c[4001];
int d[4001];

vector<int> cd;

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cd.push_back(c[i]+d[j]);
        }
    }
    sort(cd.begin(), cd.end());

    long long int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int ab = a[i] + b[j];
            ans += upper_bound(cd.begin(), cd.end(), -ab) - lower_bound(cd.begin(), cd.end(), -ab);
        }
    }
    
    cout << ans;
    return 0;
}