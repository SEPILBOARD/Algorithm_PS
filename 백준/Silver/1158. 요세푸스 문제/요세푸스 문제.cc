#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, k;
bool v[5'001];

int main()
{
    FASTIO;
    cin >> n >> k;
    
    int idx = k;
    v[idx] = true;
    int curm = 0;
    int cnt = 1;
    cout << "<" << k;
    while(cnt != n){
        idx++;
        if(idx>n) idx%=n;
        
        if(v[idx]) continue;
        curm++;
        if(curm == k){
            curm = 0;
            cout << ", " << idx;
            v[idx] = true;
            cnt++;
        }
    }
    cout << ">";
    return 0;
}