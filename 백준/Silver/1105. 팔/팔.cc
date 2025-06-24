#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

string l, r;

int main()
{
    FASTIO;
    cin >> l;
    cin >> r;

    if(l.length() != r.length()) cout << '0';

    else{
        int ans = 0;
        for(int i = 0; i<l.length(); i++){
            if(l[i] != r[i]){
                cout << ans;
                return 0;
            }
            else if(l[i] == '8' && r[i] == '8') ans++;
        }
        cout << ans;
    }
    return 0;
}