#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

string s, t;

int main()
{
    FASTIO;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();

    int ans = n+m;
    for(int k = -n; k<m; k++){
        int cnt = 0;
        bool flag = true;
        if(k<0){
            for(int i = -k, j = 0; i<n && j<m; i++, j++){
                cnt++;
                if(s[i] == '2' && t[j] == '2'){
                    flag = false;
                    break;
                }
            }
        }
        else{
            for(int i = 0, j = k; i<n && j<m; i++, j++){
                cnt++;
                if(s[i] == '2' && t[j] == '2'){
                    flag = false;
                    break;
                }
            }
        }
        if(flag) ans = min(ans, n+m-cnt);
    }
    // reverse(s.begin(), s.end());
    for(int k = -n; k<m; k++){
        int cnt = 0;
        bool flag = true;
        if(k<0){
            for(int i = -k, j = 0; i<n && j<m; i++, j++){
                cnt++;
                if(s[i] == '2' && t[j] == '2'){
                    flag = false;
                    break;
                }
            }
        }
        else{
            for(int i = 0, j = k; i<n && j<m; i++, j++){
                cnt++;
                if(s[i] == '2' && t[j] == '2'){
                    flag = false;
                    break;
                }
            }
        }
        if(flag) ans = min(ans, n+m-cnt);
    }
    // cout << m <<"\n";
    cout << ans;
    return 0;
}