#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

pair<int, int> k, r;
int q;

string cmd;
char x, y;

int main()
{
    FASTIO;
    cin >> x >> y;
    k = {x-'A', y-'1'};
    cin >> x >> y;
    r = {x-'A', y-'1'};
    cin >> q;

    while(q--){
        cin >> cmd;
        auto [ki, kj] = k;
        auto [ri, rj] = r;

        int dx = 0, dy = 0;
        if(cmd[0] == 'R') dx = 1; 
        else if(cmd[0] == 'L') dx = -1;
        else if(cmd[0] == 'T') dy = 1;
        else if(cmd[0] == 'B') dy = -1;

        if(cmd.length()>1){
            if(cmd[1] == 'R') dx = 1; 
            else if(cmd[1] == 'L') dx = -1;
            else if(cmd[1] == 'T') dy = 1;
            else if(cmd[1] == 'B') dy = -1;
        }
        int i = ki+dx;
        int j = kj+dy;
        if(i==ri && j==rj){
            if(0<=i+dx && i+dx<8 && 0<=j+dy && j+dy<8){
                r = {i+dx, j+dy};
                k = {i, j};
            }
        }
        else{
            if(0<=i && i<8 && 0<=j && j<8) k = {i, j};
        }
    }

    cout << (char)('A'+k.first) << char('1'+k.second) <<"\n";
    cout << char('A'+r.first) << char('1'+r.second) <<"\n";
    return 0;
}