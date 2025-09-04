#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int mn[2];
int ab[2][50'005];

int idg[2][50'005];
int ans[2][50'005];

queue<pair<pair<int, int>, int>> q;
bool v[2][50'005];
queue<pair<pair<int, int>, int>> q2;

signed main()
{
    FASTIO;
    cin >> mn[0] >> mn[1];
    for(int i = 0; i<2; i++){
        for(int j = 1; j<=mn[i]; j++){
            cin >> ab[i][j];
            idg[i^1][ab[i][j]]++;
            ans[i][j] = i;
        }
    }

    for(int i = 0; i<2; i++){
        for(int j = 1; j<=mn[i]; j++){
            if(idg[i][j] == 0) q.push({{i, j}, 1});
        }
    }
    
    while(!q.empty()){
        auto[p, w] = q.front();
        q.pop();
        auto[i, j] = p;
        // cout << i <<", " << j <<" : " <<w << "\n";
        ans[i][j] = w;
        if(v[i][j]) continue;

        v[i][j] = true;
        if(w == 1) q.push({{i^1, ab[i][j]}, 0});
        else if(w == 0){
            idg[i^1][ab[i][j]]--;
            if(idg[i^1][ab[i][j]] == 0){
                q.push({{i^1, ab[i][j]}, 1});
            }
        }
    }

    for(int i = 0; i<2; i++){
        for(int j = 1; j<=mn[i]; j++){
            cout << ans[i][j];
        }
        cout << "\n";
    }

    return 0;
}