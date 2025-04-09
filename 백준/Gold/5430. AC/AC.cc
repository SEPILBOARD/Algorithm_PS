#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

deque<int> dq;

void solve()
{
    dq.clear();
    int n;
    string cmd;
    cin >> cmd >> n;

    char qjflrl; cin >> qjflrl;
    for(int i = 0; i<n; i++){
        int e; cin >> e;
        dq.push_back(e);
        cin >> qjflrl;
    }
    if(n==0) cin >> qjflrl;

    int curf = 1;
    for(char c: cmd){
        if(c == 'R') curf ^= 1;
        else{
            if(!dq.size()){
                cout << "error\n";
                return;
            }
            //앞에서 버리기
            if(curf) dq.pop_front();
            else dq.pop_back();
        }
    }

    cout << '[';
    int len = dq.size();
    if(len == 0){
        cout << "]\n";
        return;
    }
    //정방향
    if(curf){
        while(len>1){
            cout << dq.front() <<',';
            dq.pop_front();
            len--;
        }
        cout << dq.front();
        dq.pop_front();
    }
    else{
        while(len>1){
            cout << dq.back() <<',';
            dq.pop_back();
            len--;
        }
        cout << dq.back();
        dq.pop_back();
    }
    cout << "]\n";
}

int main()
{
    FASTIO;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}