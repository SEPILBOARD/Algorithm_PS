#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int a[2001];
map<int,int> m;

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        m[a[i]]++;
    }

    int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(m[a[i]+a[j]]){
                if(a[i] == 0 && a[j] == 0){
                    if(m[0] <= 2) continue;
                }
                else if(a[i] == 0 || a[j] == 0){
                    if(m[a[i]+a[j]] <= 1) continue;
                }
                ans += m[a[i]+a[j]];
                m[a[i]+a[j]] = 0;
            }
        }
    }
    cout << ans;
    return 0;
}