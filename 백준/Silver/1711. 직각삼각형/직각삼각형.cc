#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define int long long int

int n;
int ans = 0;
pair<int, int> xy[1500];
int dist[3];

signed main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        int x, y;
        cin >> x >> y;
        xy[i] = {x, y};
    }

    for(int i = 0; i<n-2; i++){
        for(int j = i+1; j<n-1; j++){
            for(int k = j+1; k<n;k++){
                auto [x1, y1] = xy[i];
                auto [x2, y2] = xy[j];
                auto [x3, y3] = xy[k];
                dist[0] = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                dist[1] = (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2);
                dist[2] = (x3-x1)*(x3-x1) + (y3-y1)*(y3-y1);
                if(2*max(dist[0], max(dist[1], dist[2])) == dist[0]+dist[1]+dist[2]) ans++;
            }
        }
    }
    cout << ans;
    return 0;
}