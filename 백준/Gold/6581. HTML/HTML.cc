#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

string tok;
int cnt = 0;

int main()
{
    FASTIO;

    while(cin >> tok){
        if(tok == "<br>"){
            cout << '\n';
            cnt = 0;
        }
        else if(tok == "<hr>"){
            if(cnt > 0) cout << '\n';
            for(int i = 0; i<80; i++) cout << '-';
            cout << '\n';
            cnt = 0;
        }
        else{
            int len = (int)tok.size();
            if(cnt == 0){
                cout << tok;
                cnt = len;
            }
            else{
                if(cnt+1+len <= 80){
                    cout << ' ' << tok;
                    cnt += 1+len;
                }
                else{
                    cout << '\n' << tok;
                    cnt = len;
                }
            }
        }
    }
    cout << '\n';
    return 0;
}
