#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;
char a[15][15];
vector<pair<int, int>> crs[21];
bool rcrs[31];

int ans = 0;

void bt(int c, int cnt)
{
    if(c == 2*n-1){
        ans = max(ans, cnt);
        return;
    }

    bool flag =  false;

    for(auto [i, j]: crs[c]){
        if(a[i][j] == '0' || rcrs[n+(i-j)]) continue;
        
        flag = true;;
        rcrs[n+(i-j)] = true;

        bt(c+1, cnt+1);

        rcrs[n+(i-j)] = false;
    }
    
    if(!flag) bt(c+1, cnt);
}

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> a[i][j];
            if(a[i][j] == '1') crs[i+j].push_back({i, j});
        }
    }

    bt(0, 0);
    cout << ans;
    
    return 0;
}