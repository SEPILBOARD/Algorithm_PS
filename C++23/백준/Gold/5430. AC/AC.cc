#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

string s;
int n;
string A;


void solve()
{
    cin >> s >> n >> A;
    
    deque<int> dq;

    if(n!= 0){
        int num = 0;
        for(int i = 1; i<A.size(); i++){
            if('0'<= A[i] && A[i]<='9'){
                num = num*10 + int(A[i]-'0');
            }
            else{
                dq.push_back(num);
                num = 0;
            }
        }
    }

    int rev = 0;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == 'R'){
            rev ^= 1;
        }
        else if(s[i] == 'D'){
            if(dq.empty()){
                cout << "error\n";
                return;
            }

            if(rev){
                dq.pop_back();
            }
            else{
                dq.pop_front();
            }
        }
    }

    cout << '[';
    while(dq.size()>1){
        if(rev){
            cout << dq.back() <<",";
            dq.pop_back();
        }
        else{
            cout << dq.front() << ",";
            dq.pop_front();
        }
    }
    if(!dq.empty()) cout << dq.front();
    cout << "]\n";
}

signed main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--) solve();    
    return 0;
}