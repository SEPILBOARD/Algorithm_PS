#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

string s;
int powt[6] = {1, 10, 100, 1000, 10000};

int main()
{
    FASTIO;
    cin >> s;
    int ans = 0;
    int temp = 0;
    int num = 0;
    int idx = s.length()-1;
    int ex=0;
    for(int i = s.length()-1; i>=0; i--){
        if(s[i]>='0' && s[i]<='9'){
            num += (s[i]-'0')*powt[ex];
            ex++;
        }
        else{
            temp += num;
            ex = 0;
            num = 0;
            if(s[i] == '-'){
                ans -= temp;
                temp = 0;
            }
        }
    }
    cout << ans + num + temp;
    return 0;
}