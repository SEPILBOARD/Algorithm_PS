#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

string s;

signed main()
{
    FASTIO;
    getline(cin, s);
    s.push_back(' ');
    int l = s.length();

    bool isword = false;
    if(s[0] != '<' || s[0] != ' ') isword = true;
    int sidx = 0;
    for(int i = 0; i<l; i++){
        if(isword){
            if(s[i] == '<' || s[i] == ' '){
                reverse(s.begin()+sidx, s.begin()+i);
                if(s[i] == '<'){
                    while(s[i] != '>') i++;
                    isword = true;
                }
                sidx = ++i;
            }
        }
        if(s[i] == '<'){
            while(s[i] != '>') i++;
            isword = true;
            sidx = i+1;
        }
    }
    // reverse(s.begin(), s.begin()+8);
    // reverse(s.begin()+9, s.begin()+15);
    cout << s;
    return 0;
}