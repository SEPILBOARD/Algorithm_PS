#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;

int c[11];
int s[11];
vector<pair<string, int>> dh[11];

bool ans = false;
bool exist[6][25];
void bt(int cur_n, int cur_m)
{
    if(ans) return;
    if(cur_n == n){
        // cout << cur_m <<"\n";
        if(cur_m >= m) ans = true;
        return;
    }
    
    bool flag = true;
    for(int i = 0; i<s[cur_n]; i++){
        string d = dh[cur_n][i].first;
        int h = dh[cur_n][i].second;
        if(d == "MON"){
            if(exist[0][h]) flag = false;
        }
        else if( d == "TUE"){
            if(exist[1][h]) flag = false;
        }
        else if(d=="WED"){
            if(exist[2][h]) flag = false;
        }
        else if(d=="THU"){
            if(exist[3][h]) flag = false;
        }
        else{
            if(exist[4][h]) flag = false;
        }
    }
    if(flag){
        for(int i = 0; i<s[cur_n]; i++){
            string d = dh[cur_n][i].first;
            int h = dh[cur_n][i].second;
            if(d == "MON"){
                exist[0][h] = true;
            }
            else if( d == "TUE"){
                exist[1][h] = true;
            }
            else if(d=="WED"){
                exist[2][h] = true;
            }
            else if(d=="THU"){
                exist[3][h] = true;
            }
            else{
                exist[4][h] = true;
            }
        }
        bt(cur_n+1, cur_m+c[cur_n]);
        for(int i = 0; i<s[cur_n]; i++){
            string d = dh[cur_n][i].first;
            int h = dh[cur_n][i].second;
            if(d == "MON"){
                exist[0][h] = false;
            }
            else if( d == "TUE"){
                exist[1][h] = false;
            }
            else if(d=="WED"){
                exist[2][h] = false;
            }
            else if(d=="THU"){
                exist[3][h] = false;
            }
            else{
                exist[4][h] = false;
            }
        }

    }
    bt(cur_n+1, cur_m);
}


int main()
{
    FASTIO;

    cin >> n >> m;
    for(int i = 0; i<n; i++){
        cin >> c[i] >> s[i];
        for(int j = 0; j<s[i]; j++){
            string st;
            int h;
            cin >> st >> h;
            dh[i].push_back({st, h});
        }
    }
    bt(0, 0);

    if(ans) cout << "YES";
    else cout << "NO";

    return 0;
}