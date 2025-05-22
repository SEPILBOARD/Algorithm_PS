#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;
unordered_map<string, int> mp;
int bd[1001][1001];
int ans[1'000'001];

int main()
{
    FASTIO;
    cin >> n >> m;

    int mpidx = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            string s; cin >>s;
            if(!mp.count(s)){
                mp[s] = mpidx++;
            }
            bd[i][j] = mp[s];
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(i+1<n){
                if(bd[i][j] == bd[i+1][j]){
                    ans[bd[i][j]] = true;
                    continue;
                }
                if(i+2<n)
                if(bd[i][j] == bd[i+2][j]){
                    ans[bd[i][j]] = true;
                    continue;
                }
            }
            
            if(j+1<m){
                if(bd[i][j] == bd[i][j+1]){
                    ans[bd[i][j]] = true;
                    continue;
                }
                if(j+2<m)
                if(bd[i][j] == bd[i][j+2]){
                    ans[bd[i][j]] = true;
                    continue;
                }
            }

            if(i+2<n && j+2<m){
                int cnt = 0;
                for(int dx = 0; dx<3; dx++){
                    for(int dy = 0; dy<2; dy++){
                        if(bd[i+dx][j+dy] == bd[i][j])
                            cnt++;
                    }
                }
                if(cnt>=5) ans[bd[i][j]] = true;
            }
        }
    }

    bool flag = true;
    vector<string> a;
    for(auto [key, val]: mp){
        if(ans[val]){
            a.push_back(key);
            flag = false;
        }
    }
    sort(a.begin(), a.end());
    for(string e: a) cout << e <<"\n";
    if(flag) cout << "MANIPULATED";
    return 0;
}