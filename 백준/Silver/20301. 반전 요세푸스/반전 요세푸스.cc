#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, k, m;
bool v[5'001];
bool cw = true;

int main()
{
    FASTIO;
    cin >> n >> k >> m;
    
    int idx = k;
    v[idx] = true;
    int curm = 0;
    int cnt = 1;
    if(m == 1) cw = false;

    cout << k <<"\n";
    while(cnt != n){
        if(cw){
            idx++;
            if(idx>n) idx%=n;
            if(v[idx]) continue;

            curm++;
            if(curm == k){
                curm = 0;
                cout << idx <<"\n";
                v[idx] = true;
                cnt++;
                if(cnt%m == 0) cw = false;
            }
        }
        else{
            idx--;
            if(idx<1) idx += n;
            if(v[idx]) continue;

            curm++;
            if(curm == k){
                curm = 0;
                cout << idx <<"\n";
                v[idx] = true;
                cnt++;
                if(cnt%m == 0) cw = true;
            }
        }
    }
    return 0;
}