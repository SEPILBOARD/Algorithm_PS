#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, k;
bool ers[1001];

int main()
{
    cin >> n >> k;
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if(!ers[i]){
            cnt++;
            if(cnt == k){
                cout << i;
                return 0;
            }
            for(int j = i*i; j<=n; j+=i){
                if(ers[j]) continue;
                ers[j] = true;
                cnt++;
                if(cnt == k){
                    cout << j;
                    return 0;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}