#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
vector<int> xy[200'002];
vector<int> v[200'002];

signed main()
{
    FASTIO;
    int e;
    int cur_x = 0;
    
    cin >> n;

    cin >> e;
    xy[0].push_back(e);
    v[cur_x].push_back(false);
    for(int i = 1; i<n; i++){
        cin >> e;
        if(e <= xy[cur_x].back()) cur_x++;
        xy[cur_x].push_back(e);
        v[cur_x].push_back(false);
    }

    int cnt = 0;
    queue<pair<int, int>> q;
    for(int i = 0; i<= cur_x; i++){
        for(int j = 0; j<xy[i].size(); j++){
            if(v[i][j]) continue;

            cnt++;
            v[i][j] = true;
            q.push({i, j});
            while(!q.empty()){
                auto [x, y] = q.front();
                q.pop();

                if(y>0 && !v[x][y-1]){
                    if(xy[x][y-1] == xy[x][y]-1){
                        v[x][y-1] = true;
                        q.push({x, y-1});
                    }
                }
                if(y<(int)xy[x].size()-1 && !v[x][y+1]){
                    if(xy[x][y+1] == xy[x][y]+1){
                        v[x][y+1] = true;
                        q.push({x, y+1});
                    }
                }
                if(x>0){
                    int yidx = lower_bound(xy[x-1].begin(), xy[x-1].end(), xy[x][y]) - xy[x-1].begin();
                    if(yidx<xy[x-1].size() && xy[x][y] == xy[x-1][yidx] && !v[x-1][yidx]){
                        v[x-1][yidx] = true;
                        q.push({x-1, yidx});
                    }
                }
                if(x<cur_x){
                    int yidx = lower_bound(xy[x+1].begin(), xy[x+1].end(), xy[x][y]) - xy[x+1].begin();
                    if(yidx<xy[x+1].size() && xy[x][y] == xy[x+1][yidx] && !v[x+1][yidx]){
                        v[x+1][yidx] = true;
                        q.push({x+1, yidx});
                    }
                }
            }
        }
    }

    cout << cnt << "\n" << n;
    return 0;
}