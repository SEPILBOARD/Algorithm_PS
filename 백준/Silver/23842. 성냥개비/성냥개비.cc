#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
             //0, 1, 2, 3, 4, 5, 6, 7, 8, 9  
int cnt[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
    FASTIO;
    cin >> n;
    for(int f1 = 0; f1<=9; f1++){
        for(int s1 = 0; s1<=9; s1++){
            for(int f2 = 0; f2<=9; f2++){
                for(int s2 = 0; s2<=9; s2++){
                    int ans = 10*(f1+f2)+s1+s2;
                    if(ans>=100) continue;

                    int tcnt = cnt[f1]+cnt[s1]+cnt[f2]+cnt[s2]+4 +cnt[ans/10]+cnt[ans%10];
                    if(tcnt != n) continue;

                    cout << f1<<s1 << "+" << f2<<s2 << "=" << ans/10<<ans%10 <<"\n";
                    return 0;
                }
            }
        }
    }
    cout << "impossible";
    return 0;
}