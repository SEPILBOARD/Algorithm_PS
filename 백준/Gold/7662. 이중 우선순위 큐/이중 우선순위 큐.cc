#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long int ll;

int n;
char c;
int x;

void solve()
{
    priority_queue<int> mxq;
    priority_queue<int, vector<int>, greater<int>> mnq;
    
    int tcnt = 0;
    map<int, int> cnt;

    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> c >> x;
        if(c == 'I'){
            mxq.push(x);
            mnq.push(x);
            cnt[x]++;
            tcnt++;
        }
        else{
            if(tcnt == 0) continue;

            if(x == 1){
                int t = mxq.top();
                while(cnt[t] == 0){
                    mxq.pop();
                    t = mxq.top();
                }
                cnt[t]--;
                tcnt--;
                mxq.pop();
            }
            else{
                int t = mnq.top();
                while(cnt[t] == 0){
                    mnq.pop();
                    t = mnq.top();
                }
                cnt[t]--;
                tcnt--;
                mnq.pop();
            }
        }
    }

    if(tcnt == 0) cout << "EMPTY\n";
    else{
        int t = mxq.top();
        while(cnt[t] == 0){
            mxq.pop();
            t = mxq.top();
        }
        cout << t <<" ";
        
        t = mnq.top();
        while(cnt[t] == 0){
            mnq.pop();
            t = mnq.top();
        }
        cout << t <<"\n";
    }
}

signed main()
{
    FASTIO;
    int _tc; cin >> _tc;
    while(_tc--) solve();
    return 0;
}