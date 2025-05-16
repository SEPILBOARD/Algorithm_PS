#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
string s[101];
string mobis = "MOBIS";
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++) cin >> s[i];

    int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(s[i][j] == 'S'){
                for(int k = 0; k<8; k++){
                    int m = 3;
                    bool flag = true;
                    for(int a = 1; a<=4; a++){
                        int x = i+a*dx[k];
                        int y = j+a*dy[k];
                        if(x<0 || x>=n || y<0 || y>=n){
                            flag = false;
                            break;
                        }
                        if(s[x][y] != mobis[m]){
                            flag = false;
                            break;
                        }
                        m--;
                    }
                    if(flag) ans++;
                }
            }
        }
    }

    cout << ans;
    return 0;
}