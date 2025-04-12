#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int a[16][16];
int dp[15][1<<15];

int main()
{
    FASTIO;
    
    vector<string> v;
    string s;
    while(getline(cin, s)){
        memset(dp, 0, sizeof(dp));
        
        //입력
        istringstream iss(s);
        vector<int> v;
        int e, n;
        while(iss >> e) v.push_back(e);
        n = v.size();

        if(n==1){
            cout << v[0] <<"\n";
            getline(cin, s);
            continue;
        }

        for(int i = 0; i<n; i++){
            a[0][i] = v[i];
        }
        for(int i = 1; i<n; i++){
            int idx = 0;
            getline(cin, s);
            istringstream iss(s);
            while(iss >> e){
                a[i][idx] = e;
                idx++;
            }
        } //입력 끝

        vector<int> psb;
        for(int i = 0; i< 1<<n; i++){
            bool flag = true;
            for(int j = 0; j<n-1; j++){
                if(i&(1<<j) && i&(1<<(j+1))){
                    flag = false;
                    break;
                }
            }
            if(flag){
                psb.push_back(i);
            }
        }
        
        for(int state: psb){
            for(int i = 0; i<n; i++){
                if(state&(1<<i)) dp[0][state] += a[0][i];
            }
        }

        for(int i = 0; i<n-1; i++){
            for(int cl: psb){
                for(int nl: psb){
                    bool flag = true;
                    for(int j = 0; j<n; j++){
                        if(cl&(1<<j)){
                            if((j!=0 && nl&(1<<(j-1)))){
                                flag = false;
                                break;
                            }
                            if(nl&(1<<j)){
                                flag = false;
                                break;
                            }
                            if(j!=(n-1) && nl&(1<<(j+1))){
                                flag =false;
                                break;
                            }
                        }
                    }
                    if(flag){
                        int nlsum = 0;
                        for(int j = 0; j<n; j++){
                            if(nl&(1<<j)) nlsum += a[i+1][j];
                        }
                        dp[i+1][nl] = max(dp[i+1][nl], dp[i][cl]+nlsum);

                        // bitset<32> b(cl);
                        // bitset<32> k(nl);
                        // cout <<i <<": "<<b <<" -> " << k <<": " <<dp[i+1][nl] <<"\n";
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<1<<n; i++){
            ans = max(ans, dp[n-1][i]);
        }

        // for(int i = 0; i<1<<n; i++){
        //     if(dp[n-1][i] != 0){
        //         bitset<32> b(i);
        //         cout << b <<": " <<dp[1][i] <<"\n";
        //     }
        //     ans = max(ans, dp[n-1][i]);
        // }

        // for(int state: psb){
        //     bitset<32> b(state);
        //     cout << b <<" ";
        // }

        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<n; j++){
        //         cout << a[i][j] <<" ";
        //     }
        //     cout << "\n";
        // }

        cout << ans <<"\n";
        getline(cin, s);
    }

    return 0;
}