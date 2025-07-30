#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, k, l;
char g[105][105];
int cur = 0;
int t = 0;

deque<pair<int, int>> dq;
// void prtbd()

signed main()
{
    FASTIO;
    cin >> n >> k;
    for(int i = 0; i<k; i++){
        int x, y;
        cin >> x >> y;
        g[x][y] = 'a';
    }
    for(int i = 0; i<=n+1; i++) g[0][i] = 'X';
    for(int i = 0; i<=n+1; i++) g[n+1][i] = 'X';
    for(int i = 0; i<=n+1; i++) g[i][0] = 'X';
    for(int i = 0; i<=n+1; i++) g[i][n+1] = 'X';
    g[1][1] = 'X';

    cin >> l;
    dq.push_back({1,1});
    while(l--){
        int et; char c;
        cin >> et >> c;

        //입력 시점까지 이동
        while(t != et){
            t++;
            int dx = 0, dy = 0;
            if(cur == 0) dy = 1;
            else if(cur == 90) dx = -1;
            else if(cur == 180) dy = -1;
            else if(cur == 270) dx = 1;

            auto[x, y] = dq.front();
            int nx = x+dx;
            int ny = y+dy;
            
            if(g[nx][ny] == 'X'){
                cout << t;
                return 0;
            }
            else if(!(g[nx][ny] == 'a')){
                g[dq.back().first][dq.back().second] = NULL;
                dq.pop_back();
            }
            g[nx][ny] = 'X';
            dq.push_front({nx, ny});

            // prtbd();
        }

        //방향 전환
        if(c == 'L') cur += 90;
        else cur -= 90;
        if(cur < 0) cur += 360;
        else if(cur >= 360) cur -= 360;
    }

    while(true){
        t++;
        int dx = 0, dy = 0;
        if(cur == 0) dy = 1;
        else if(cur == 90) dx = -1;
        else if(cur == 180) dy = -1;
        else if(cur == 270) dx = 1;

        auto[x, y] = dq.front();
        int nx = x+dx;
        int ny = y+dy;
        
        if(g[nx][ny] == 'X'){
            cout << t;
            return 0;
        }
        else if(!(g[nx][ny] == 'a')){
            g[dq.back().first][dq.back().second] = NULL;
            dq.pop_back();
        }
        g[nx][ny] = 'X';
        dq.push_front({nx, ny});
    }
    return 0;
}


// void prtbd()
// {
//     for(int i = 1; i<=n; i++){
//         for(int j = 1; j<=n; j++){
//             cout << g[i][j] <<" ";
//         }
//         cout << "\n";
//     }
//     cout << "\n";
// }